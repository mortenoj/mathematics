#include <iostream>
#include <vector>       /* vector */
#include <math.h>       /* sqrt */

auto filter = [](auto pred, auto& cnt) {
        auto retval = cnt;
        retval.erase(std::remove_if(retval.begin(), retval.end(), [=](auto x) {return !pred(x);}), retval.end());
        return retval;
    };

std::vector<int> numbers;

int main(int argc, char const *argv[]) {
    for (int i = 2; i <= 10000; i++) {
        numbers.push_back(i);
    }

    int i = 0;
    int x = numbers[i];
    while(x < sqrt(10000)) {
        // remove all multiples of x, except x itself, from numbers.
        numbers = filter([x](auto num) {return num % x == 0;}, numbers);

        i++;
        x = numbers[i];
    };

    /*
        The numbers array consist of a sequence where every next number in the list is 
        the sum of the previous number and the first number.
    */

    std::cout << std::endl;
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers.at(i) << ", ";
    }
    std::cout << std::endl;

    return 0;
}
