// Example program
#include <iostream>
#include <cstdlib>
#include <ctime>

bool hasTwoPairs(int dice[4]);

bool roll() {
    int dice[4];
    for (int i = 0; i < 4; i++) {
        int randNum = (rand() % 6) + 1;
        dice[i] = randNum;
    }
    return hasTwoPairs(dice);
}

bool hasTwoPairs(int dice[4]) {
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (dice[i] == dice[j]) {
                counter++;
            }
        }
    }
    
    if (counter == 2) {
        return true;
    }
    
    return false;
    
}

int main() {
    int simulations = 1000;
    int counter = 0;
    srand(time(NULL));
    for (int i = 0; i < simulations; i++) {
        if (roll()) {
            counter++;
        }
    }
    
    double result = counter / (double)simulations;
 
    std::cout << "simulation: " << counter << " / " << simulations << " = " << result << std::endl;
}