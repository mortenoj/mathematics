#include <iostream>


int main(int argc, char const *argv[]) {
    


    int a = 4, b = 3;
    std::cout << "initial values of a and b: a = " << a << " b = " << b << std::endl;

    a = a^b;
    b = a^b;
    a = a^b;

    std::cout << "new values of a and b:     a = " << a << " b = " << b << std::endl;



    // Clearing and setting bits

    int x = 10;
    std::cout << "initial x" << x << std::endl;
    
    x = x & ~(1 << 10);
    x = x | (1 << 10);
    x = x ^ (1 << 10);

    std::cout << "after bit logic: x" << x << std::endl;
    // std::cout << "in hex: " << std::hex << x << std::endl;



    // Multiply, divide and modulo 2^n
    x = 10;
    int y;
    int n = 4;

    y = x << n;
    y = x >> n;
    y = x & ((1<<n) - 1);

    std::cout << "Multiply, divide and modulo 2^n: " << y << "\n";

    int x = 12124;
    int c = 0;
    while(x) {
        c++;
        // we clear least signifiant bit
        x = x & (x-1);
    }

    std::cout << "X: " << x <<"\nc: " << c <<"\n\n";



    return 0;
}
