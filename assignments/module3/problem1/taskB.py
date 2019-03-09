import itertools as it

# Function for printing out probability based on event and sample space
def printProbability(eventspace, samplespace):
        probability = len(eventspace) / len(samplespace)
        print(f'|S|: {len(samplespace)}, |P|: {len(eventspace)}')
        print(f'The probability(|P| / |S|) is: {probability} or {probability*100}%\n\n')

# ---------------------------------------------------------------------------------

# Checks is a set of 6 throws throws contain 6 unique values
def uniqueThrow(throw):
        return (throw.count(1) == 1
                and throw.count(2) == 1
                and throw.count(3) == 1
                and throw.count(4) == 1
                and throw.count(5) == 1
                and throw.count(6) == 1)

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

        # Define event by filter samplespace by unique set of throws
        event = list(filter(lambda throw: uniqueThrow(throw), samplespace))

        print("Problem 1: Six values for 6 dice throws")
        printProbability(event, samplespace)

# ---------------------------------------------------------------------------------
# Returns how many times a value occurs in a hand
def cardOccurance(hand, value):
        return len([ card for card in hand if card[1] == value])

# Checks if a 5 card hand only contains unique values
def uniqueHand(hand):
        return (cardOccurance(hand, 1) < 2
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
                and cardOccurance(hand, 13) < 2)

def problem2():
        # Define a deck of cards with 1-4 suits and 1-13
        deck = list( it.product(range(1,5), range(1,14)) )
        
        # Define a sample space with every combination of 5 cards of a deck        
        samplespace = list (it.combinations(deck, 5))

        # Define event by filtering all hands from the samplespace by unique hands
        event = list(filter(lambda hand: uniqueHand(hand), samplespace))

        print("Problem 2: 5 unique values in a deck")
        printProbability(event, samplespace)

# ---------------------------------------------------------------------------------
# Checks if a queue is sorted alphabetically
def sorted(queue):
    return (queue[0] == "A"
        and queue[1] == "B"
        and queue[2] == "C"
        and queue[3] == "D"
        and queue[4] == "E")

# Probability of 5 people ABCD and E are queued up alphabetically
def problem3():
        # People array
        people = ["A", "B", "C", "D", "E"]

        # Samplespace defined by all permutations of people list
        samplespace = list(it.permutations(people))

        # Define event by filtering all queues from samplespace where a queue is sorted
        event = list(filter(lambda queue: sorted(queue), samplespace))

        print("Problem 3: A,B,C,D and E is queued up in alphabetical order")
        printProbability(event, samplespace)

problem1()
problem2()
problem3()

