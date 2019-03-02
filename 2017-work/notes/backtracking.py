
st = [1,2,3, ... , 100];    # Stack
st.append(1000);            # Pushes a number in the last place
st.pop();                   # Removes the last number
st[-1];                     # top of stack


puzzle = [[1,2,3,4,5,6,7,8,9], for i in range(9)];
puzzle = [];
puzzle.append(start);

# BACKTRACKING
# While there are puzzles in the stack
    # While the puzzle is changing
        # Fill in blanks
        # Remove numbers from list
        # if contradiction (i.e a tile where no numbers will fit)
            # this puzzle is invalid
            # pop puzzle of stack
        # if all singletons
            # print solution
        # Find position with at two elements
            # push 
