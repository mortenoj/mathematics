
#include <iostream>
#include <unordered_map>

// Method for printing out the board
void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << " " << board[i][j] << " ";
        } 
        std::cout <<"\n";
    }
    std::cout << "\n";
}

// Returns false if there is an empty entry
bool isFull(int board[9][9]) {
    for (int x = 0; x < 9; x++)
        for (int y = 0; y < 9; y++)
            if (board[x][y] == 0)
                return false;

    return true;
}

// Returns a list of possible values for an entry in the board
std::unordered_map<int, int> possibleEntries(int board[9][9], int i, int j) {

    // List of possibilities
    std::unordered_map<int, int> possibilityArr;

    // Loop from 1 to 10 because valid values in sudoku is 1..9
    for (int i = 1; i < 10; i++) {
        possibilityArr[i] = 0;
    }

    // Fill posibility arr with 1's if there is a possible value available horizontally
    for (int y = 0; y < 9; y++) {
        if (board[i][y] != 0) {
            possibilityArr[board[i][y]] = 1;
        }
    }

    // Fill posibility arr with 1's if there is a possible value available vertically
    for (int x = 0; x < 9; x++) {
        if (board[x][j] != 0) {
            possibilityArr[board[x][j]] = 1;
        }
    }

    // For squares of three times three
    int k, l = 0;

    // K and L points to the start (top left) value of a 3x3 block in the puzzle
    if      (i >= 0 && i <= 2)   k = 0;
    else if (i >= 3 && i <= 5)   k = 3;
    else                         k = 6;

    if      (j >= 0 && j <= 2)   l = 0;
    else if (j >= 3 && j <= 5)   l = 3;
    else                         l = 6;

    // Fill posibility arr with 1's if there is a possible value available in 3x3 blocks
    for (int x = k; x < k+3; x++)
        for (int y = l; y < l+3; y++)
            if (board[x][y] != 0)
                possibilityArr[board[x][y]] = 1;

    // Assign possible values of the entries to the possibility arr
    for (int i = 1; i < 10; i++) {
        if (possibilityArr[i] == 0)
            possibilityArr[i] = i;
        else // possibilityArr[i] == 1 means that there is already a possible solution there
           possibilityArr[i] = 0;
    }

    return possibilityArr;
}

// Recursivly uses possible entries method and backtracking to solve puzzle
void sudokuSolver(int board[9][9]) {
    // Current entry
    int i, j = 0;

    // List of possibilities
    std::unordered_map<int, int> possibilities;

    if (isFull(board)) {
        std::cout << "Sudoku puzzle is solved! \n";
        printBoard(board);
        return;
    } else {
        // Initialise i and j to the first empty entry
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (board[x][y] == 0) {
                    i = x;
                    j = y;
                    break;
                }
            }   
        }

        // Get all possible entries for i and j (empty entry)
        possibilities = possibleEntries(board, i, j);

        // Go through all the possibilities and call the method again
        for (int x = 1; x < 10; x++) {
            if (possibilities[x] != 0) {
                // Fill the board with correct possible value
                board[i][j] = possibilities[x];
             
                // Call solver again with the new value inputed
                sudokuSolver(board);
            }
        }

        // Backtrack
        board[i][j] = 0;
    }

}


int main(int argc, char const *argv[]) {
    int easyBoard[9][9] = {
        {0, 0, 0, 3, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 8, 0, 0, 0},
        {0, 7, 8, 0, 6, 0, 3, 4, 0},
        {0, 4, 2, 5, 1, 0, 0, 0, 0},
        {1, 0, 6, 0, 0, 0, 4, 0, 9},
        {0, 0, 0, 0, 8, 6, 1, 5, 0},
        {0, 3, 5, 0, 9, 0, 7, 6, 0},
        {0, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 9, 0, 0, 5, 0, 0, 0}
    };

    int mediumBoard[9][9] = {
        {0, 5, 0, 7, 0, 4, 6, 0, 0},
        {3, 0, 0, 9, 0, 0, 4, 0, 0},
        {1, 0, 0, 5, 0, 0, 0, 0, 0},
        {0, 7, 0, 6, 0, 0, 5, 0, 9},
        {0, 0, 3, 0, 0, 0, 7, 0, 0},
        {8, 0, 5, 0, 0, 7, 0, 2, 0},
        {0, 0, 0, 0, 0, 5, 0, 0, 4},
        {0, 0, 8, 0, 0, 2, 0, 0, 1},
        {0, 0, 6, 1, 0, 9, 0, 8, 0}
    };

    int hardBoard[9][9] = {
        {0, 3, 2, 1, 0, 0, 7, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 5},
        {8, 0, 0, 0, 6, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 3, 5, 0, 2, 9, 0, 4},
        {0, 0, 0, 9, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 8, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 1, 0, 0, 9, 6, 7, 0}
    };

    std::cout << "Difficulty: EASY \n";
    sudokuSolver(easyBoard);

    std::cout << "Difficulty: MEDIUM \n";
    sudokuSolver(mediumBoard);

    std::cout << "Difficulty: HARD \n";
    sudokuSolver(hardBoard);

    return 0;
}
