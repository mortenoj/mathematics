#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>


int factorial(int n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void problem1() {
    /*
        Calculate the probability of throwing six different numbers when 
        you throw six dice.
        
        The probability of each roll satisfying our requirement:
        1st roll: any of the 6 values will do:                                     (6/6)
        2nd roll: there is 1 value from the last roll which can't be rolled again: (5/6)
        3nd roll: there is 1 value from the last roll which can't be rolled again: (4/6)
        4th roll: there is 1 value from the last roll which can't be rolled again: (3/6)
        5th roll: there is 1 value from the last roll which can't be rolled again: (2/6)
        6th roll: there is only 1 value left which has not been roll before:       (1/6)

        The probability of getting all 6 sides of a dice on 6 throws is therefor
        (6/6) * (5/6) * (4/6) * (3/6) * (2/6) * (1/6);
        This is the same as 6! / 6^6
    */

    float probability = factorial(6) / std::pow(6, 6);

    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    std::cout << "\n-------------------------------Problem1----------------------------------------\n\n";
    std::cout << "The chance of rolling all six different values on six dice throws is \n\n"
              << probability << "\n"
              << "or \n"
              << probability*100 << "\%" << "\n";
}

void problem2() {
    /*
        Calculate the probability of drawing five different values when you draw five 
        cards from a deck of 52 cards.

        The probability of each draw satisfying our requirement:
        1st draw: any of 52 cards out of 52 cards will do: (52/52)
        2nd draw: there are 4 cards from the previous draw which can't be redrawn: (48/52)
        3rd draw: there are 4 cards from the previous draw which can't be redrawn: (44/52)
        4th draw: there are 4 cards from the previous draw which can't be redrawn: (40/52)
        5th draw: there are 4 cards from the previous draw which can't be redrawn: (36/52)
        
        The probability of drawing five different values when you draw five cards from a
        deck of 52 cards will therefor be:
        
        (52/52) * (48/52) * (44/52) * (40/52) * (36/52);
    */

    float probability = (52.0f/52.0f) * (48.0f/52.0f) * (44.0f/52.0f) * (40.0f/52.0f) * (36.0f/52.0f);

    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    std::cout << "\n-------------------------------Problem2----------------------------------------\n\n";
    std::cout << "The chance of drawing 5 different values on five draws of a deck is \n\n"
              << probability << "\n"
              << "or \n"
              << probability * 100 << "\%" << "\n";

}

void problem3() {
    /*
        Calculate the probability that the five people A, B, C, D
        and E are placed in alphabetical order when they are randomly placed
        in a queue.

        There are 5! combinations

        There are only 1 combination where they are sorted in alphabetical order
        
        Therefor the probability is 1/5!
    */

    float probability = 1.0f / factorial(5);

    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    std::cout << "\n-------------------------------Problem3----------------------------------------\n\n";
    std::cout << "The chance of A, B, C, D and E are queued in alphabetical order is \n\n"
              << probability << "\n"
              << "or \n"
              << probability * 100 << "\%" << "\n";
}


void uniformIntDistribution(int from, int to, int amount, int precision) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(from, to);

    std::cout << std::fixed;
    std::cout << "\n--------------------------Uniform integer distribution-------------------------\n\n"
              << amount << " random integers between " << from << " and " << to << "\n\n";
    for (int n=0; n < amount; ++n)
        std::cout << dis(gen) << ' ';
    std::cout << '\n';
}

void uniformFloatDistribution(float from, float to, int amount, int precision) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(from, to);

    std::cout << std::fixed;
    std::cout << std::setprecision(precision);
    std::cout << "\n---------------------Uniform floating numbers distribution---------------------\n\n"
              << amount << " random floating numbers between " << from << " and " << to
              << "\nPrint out precision set to: " << precision << " decimal places" << "\n\n";
    for (int n=0; n < amount; ++n)
        std::cout << dis(gen) << ' ';
    std::cout << '\n';
}


int main(int argc, char const *argv[]) {
    problem1();
    problem2();
    problem3();

    uniformIntDistribution(0, 999, 10, 3);
    uniformFloatDistribution(5.0f, 888.0f, 10, 3);


    return 0;
}
