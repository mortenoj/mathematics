import itertools as it

def printProbability(eventspace, samplespace):
    probability = len(eventspace) / len(samplespace)
    print(f'|S|: {len(samplespace)}, |P|: {len(eventspace)}')
    print(f'The probability(|P| / |S|) is: {probability} or {probability*100}%\n\n')

# ---------------------------------------------------------------------------------

def uniqueRoll(roll):
    return (roll.count(1) == 1
        and roll.count(2) == 1
        and roll.count(3) == 1
        and roll.count(4) == 1
        and roll.count(5) == 1
        and roll.count(6) == 1)

def problem1():
    samplespace = [(d1, d2, d3, d4, d5, d6)
                        for d1 in range(1,7)
                        for d2 in range(1,7)
                        for d3 in range(1,7)
                        for d4 in range(1,7)
                        for d5 in range(1,7)
                        for d6 in range(1,7)
                ]
    
    event = list(filter(lambda roll: uniqueRoll(roll), samplespace))

    print("Problem 1: Six values for 6 dice throws")
    printProbability(event, samplespace)

# ---------------------------------------------------------------------------------

def cardOccurance(hand, value):
    return len([ card for card in hand if card[1] == value])

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
    deck = list( it.product(range(1,5), range(1,14)) )
    
    samplespace = list (it.combinations(deck, 5))

    event = list(filter(lambda hand: uniqueHand(hand), samplespace))

    print("Problem 2: 5 unique values in a deck")
    printProbability(event, samplespace)

# ---------------------------------------------------------------------------------

def sorted(queue):
    return (queue[0] == "A"
        and queue[1] == "B"
        and queue[2] == "C"
        and queue[3] == "D"
        and queue[4] == "E")

def problem3():
    people = ["A", "B", "C", "D", "E"]
    samplespace = list(it.permutations(people))
    event = list(filter(lambda queue: sorted(queue), samplespace))

    print("Problem 3: A,B,C,D and E is queued up in alphabetical order")
    printProbability(event, samplespace)

problem1()
problem2()
problem3()

