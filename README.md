Game: Sudoku, a board game that include 9 3x3 blocks where contains numbers 1-9. No duplicate in each block, row and column is allowed. 

Features: 
1. Reset option
2. Delete function
3. Provide different difficulties to the player
4. Hint
5. Save game

How the game will apply the code requirement:
1. Generation of random game sets or events: sudoku game board will be generated randomly
2. Data structures for storing game status: 2D array will be used to store the board status
3. Dynamic memory management: ???
4. File input/output (e.g., for loading/saving game status): Game status can be saved and opened if the game is not finished
5. Program codes in multiple files: Different functions will be put in different files

Non-standard C/C++ libraries:
'save.h': for saving the boards and game progress
'print.h': print the user interface
'make.h': for generating functions and gameplay flows

Compilation and execution instructions:
1. Choose a value among 1-3 to decide:
   1. NEW GAME | 2. CONTINUE LAST GAME | 3. EXIT
2. Then choose a value among 1-3 to decide the difficulty:
   1. EASY   | 2. INTERMEDIATE  |  3. HARD
3. Choose during gameplay to:
   A. ADD A DIGIT | B. DELETE AN INPUT | H. HINT | L. LEAVE THE GAME
4. If choosing 'L' in step 3, choose to save or check the game:
   SAVE: your input will be saved
   CHECK: your board will be checked
