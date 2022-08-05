# SudokuGeneration
Collaborative project on generating sudoku puzzles

ALGORITHM DOCUMENTATION
-----------------------
First call a solve sudoku function to return a solved board (the board must random)
Then loop over random indicies, removing them, and checking if the puzzle has one solution
If the puzzle ends up having one solution, remove another one, and another one as long as the puzzle has one solution
So, we want a sudoku puzzle that has the least amount of slots filled that still has one solution
If the puzzle does not have one solution, put the removed number back, and go to the next random index
Eventually, we can return the board with some of its indices removed