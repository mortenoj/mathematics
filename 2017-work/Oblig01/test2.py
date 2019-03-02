import numpy as np
np.set_printoptions(precision=2)

# define the transition matrix
P = np.array([[0,    1/3., 1/3., 1/3., 0,    0,    0,    0],
              [0,    0,    1/3., 2/3., 0,    0,    0,    0],
              [0,    0,    0,    2/3., 0,    0,    1/3., 0],
              [0,    1/3., 0,    0,    1/3., 0,    1/3., 0],
              [0,    0,    0,    0,    1/3., 1/3., 1/3., 0],
              [0,    0,    0,    0,    0,    0,    1/3., 2/3.],
              [0,    0,    0,    0,    0,    0,    0,    1],
              [0,    0,    0,    0,    0,    0,    0,    1]], dtype=np.float64)

print P


# find the fundamental matrix N
Q = P[:-1, :-1]
I = np.eye(7)
N = np.linalg.inv(I - Q)

# find mean steps until absorption -- we only care about the first element
# since the rules say we always start in the first state
print N.dot(np.ones(7)).ravel()[0]


def move(state, P):
    """
    Execute one transition from the current state, returns new state.

    state -- an int representing the current state
    P -- transition matrix
    """
    possible = P[state, :].nonzero()[0]
    probs = P[state, possible].cumsum()
    return possible[probs >= np.random.rand()].min()

def play_chutes_and_ladders(P):
    """
    Play a game of chutes and ladders, return the number of moves.

    P -- transition matrix
    """

    # initialize the game
    state = 0
    moves = 0

    while state < 7:
        state = move(state, P)
        moves += 1

    return moves

# run a bunch of simulations and find out the average number of moves
N = 100000
results = np.array([play_chutes_and_ladders(P) for _ in xrange(N)])
print 'mean moves to finish', results.mean()
