import itertools as it

# Function for printing out probability based on event and sample space
def printProbability(eventspace, samplespace):
    probability = len(eventspace) / len(samplespace)
    print(f'|S|: {len(samplespace)}, |P|: {len(eventspace)}')
    print(f'The probability(|P| / |S|) is: {probability} or {probability*100}%\n\n')

# ---------------------------------------------------------------------------------
# What is the probability of rolling all unique values on 6 dice throws
def problem1():
        # Define sample space based on all possible values possible on 6 throws
        # |S| = 6^6 containing every possible combination of values
        samplespace = [(d1, d2, d3, d4, d5, d6)
                                for d1 in range(1,7)
                                for d2 in range(1,7)
                                for d3 in range(1,7)
                                for d4 in range(1,7)
                                for d5 in range(1,7)
                                for d6 in range(1,7)
                        ]
        
        # Define expected event
        # throw.count(x) == 1 means that value x only appeared one time in the set of throws
        # go through every possible throw in the sample space and 
        # check if the values 1 through 6 only appears once
        event = [ throw for throw in samplespace if throw.count(1) == 1
                                                and throw.count(2) == 1
                                                and throw.count(3) == 1
                                                and throw.count(4) == 1
                                                and throw.count(5) == 1
                                                and throw.count(6) == 1
                ]

        print("Problem 1: Six values for 6 dice throws")
        printProbability(event, samplespace)

# ---------------------------------------------------------------------------------
# Returns how many times a value occurs in a hand
def cardOccurance(hand, value):
        return len([ card for card in hand if card[1] == value])


def problem2():
        # Define a deck of cards with 1-4 suits and 1-13
        deck = list( it.product(range(1,5), range(1,14)) )

        # Define a sample space with every combination of 5 cards of a deck        
        samplespace = list (it.combinations(deck, 5))

        # Loop through all hands in samplespace and yse cardOccurance method
        # to check if the hand contains unique values
        event = [ hand for hand in samplespace if cardOccurance(hand, 1) < 2
                                                and cardOccurance(hand, 2) < 2
                                                and cardOccurance(hand, 3) < 2
                                                and cardOccurance(hand, 4) < 2
                                                and cardOccurance(hand, 5) < 2
                                                and cardOccurance(hand, 6) < 2
                                                and cardOccurance(hand, 7) < 2
                                                and cardOccurance(hand, 8) < 2
                                                and cardOccurance(hand, 9) < 2
                                                and cardOccurance(hand, 10) < 2
                                                and cardOccurance(hand, 11) < 2
                                                and cardOccurance(hand, 12) < 2
                                                and cardOccurance(hand, 13) < 2
                ]

        print("Problem 2: 5 unique values in a deck")
        printProbability(event, samplespace)

# ---------------------------------------------------------------------------------
def problem3():
        # People ABCD and E
        people = ["A", "B", "C", "D", "E"]

        # Define samplespace of all permutations (queues) of people list
        samplespace = list(it.permutations(people))

        # Go through all queues in the samplespace and check if the queue is alphabetical
        event = [queue for queue in samplespace if queue[0] == "A"
                                                and queue[1] == "B"
                                                and queue[2] == "C"
                                                and queue[3] == "D"
                                                and queue[4] == "E"
                ]

        print("Problem 3: A,B,C,D and E is queued up in alphabetical order")
        printProbability(event, samplespace)

problem1()
problem2()
problem3()

