import numpy as np;

boardSize = 6*6;
idMatrix = np.matrix(np.identity(boardSize + 1));

def emptySnakes():
    trans = np.zeros((boardSize + 1, boardSize + 1));
    for i in range(boardSize + 1):
        for j in range(6):
            if(i+j < boardSize):
                trans[i][i+j+1] = 1.0/6.0;
        for j in range(6):
            trans[35-j, 36] = 1.0-(j/6);

    trans[36][36] = 1;
    return trans;

def createShortcut(fromState, toState):
    for i in range(boardSize + 1):
        trans[i, toState] += trans[i, fromState];
        trans[i, fromState] = 0;
    return trans;

trans = emptySnakes();



#Ladders
createShortcut(4, 10);
createShortcut(15, 20);
createShortcut(11, 20);
createShortcut(18, 24);

#Snakes
createShortcut(12, 2);
createShortcut(30, 10);
createShortcut(32, 28);
createShortcut(20, 5);


def meanThrows():
    result = trans;
    for i in range(0,100):
        if result[0][36] > 0:
            print "Mean number of throws is: ",i;
            break;
        result = np.dot(result, trans);


def percentage(numPercent):
    result = trans;
    for i in range(300):
        if result[0][36] >= numPercent:
            print "After ", i, " throws is the probability of completing the game bigger than ", numPercent * 100, "%.";
            break;
        print result[0][36];
        result = np.dot(result, trans);


meanThrows();
percentage(0.5);
