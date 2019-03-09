#include <iostream>

bool check(int arr[9][9], int j) {
    bool ret = true;
    for (int i = 0; i < 9; i++) {
        if (arr[i][j] != 1) {
            ret = false;
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int arr[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            arr[i][j] = 2;
        }   
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 2)
                arr[i][j] = 1;
        }
    }

    for (int j =  0; j < 9; j++) {
        if (check(arr, j)) {
            std::cout << "at: " << j << std::endl;
        }
    }
    

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
