import scipy as scpy;
import random;
import operator;

def throw(rolls):
    dices = [0, 0, 0, 0, 0, 0];
    for i in range(rolls):
        dices[random.randint(0, 5)] += 1;
    return dices;

def findEquals(dices):
    highest = 0;
    for i in range(len(dices)):
        if(dices[highest] < dices[i]):
            highest = i;
    return highest;

def reThrow(dices, rethrows):
    dice = [0,0,0,0,0,0];
    highestNumber = findEquals(dices);
    if(dices[highestNumber] == 5):
        return True;
    if rethrows == 0:
        return False;
    dice[highestNumber] = dices[highestNumber];
    newThrow = map(operator.add, dice, throw(5 - dices[highestNumber]));

    return reThrow(newThrow, rethrows-1);

count = 0;
for i in range(0,1000000):
    if reThrow(throw(5), 3):
        count += 1

print(count / 10000.)
