import numpy as np
import random
import operator

def throwDice(throws) :
    dice = [0,0,0,0,0,0]
    for i in range(0,throws):
        dice[random.randint(0,5)] += 1
    return dice

def yahtzee(dices):
    return (max(dices) == 5)

def findAndRethrow(dices, times):
    index, value = max(enumerate(dices), key=operator.itemgetter(1))
    dice = [0,0,0,0,0,0]
    dice[index] = value
    if yahtzee(dice):
        return True

    if times > 0:
        diceRethrow = throwDice(5 - value)
        dice = map(operator.add, dice, diceRethrow)
        return findAndRethrow(dice, times-1)
    return False


simuls = 1000000


for j in range(0,1):
    count   = 0
    i       = 0
    while i < simuls:
        if findAndRethrow(throwDice(5), j):
            count += 1
        i += 1
    print(count / (simuls / 100.0));
    if(count / (simuls / 100.0) >= 90):
        print(j);
        break;

# Find the max number and it's position
