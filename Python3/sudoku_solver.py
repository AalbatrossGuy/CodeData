# Solves a sudoku using the backtracing algorithm

"""
The backtracing algorithm:
Create a function that checks after assigning the current index the grid becomes unsafe or not. Keep Hashmap for a row, column and boxes.
If any number has a frequency greater than 1 in the hashMap return false else return true; hashMap can be avoided by using loops.
Create a recursive function that takes a grid.
Check for any unassigned location. If present then assign a number from 1 to 9, check if assigning the number to current
index makes the grid unsafe or not, if safe then recursively call  the function for all safe cases from 0 to 9.
if any recursive call returns true, end the loop and return true. If no recursive call returns true then return false.
If there is no unassigned location then return true.

"""


def show_grid(arr):
    for i in range(9):
        for j in range(9):
            print(arr[i][j], end=" ")
        print('')


def find_empty_location(arr, record_pos):
    for row in range(9):
        for col in range(9):
            if arr[row][col] == 0:
                record_pos[0] = row
                record_pos[1] = col
                return True
    return False


def used_in_row(arr, row, num):
    for i in range(9):
        if arr[row][i] == num:
            return True
    return False


def used_in_col(arr, col, num):
    for i in range(9):
        if arr[i][col] == num:
            return True
    return False


def used_in_box(arr, row, col, num):
    for i in range(3):
        for j in range(3):
            if arr[i + row][j + col] == num:
                return True
    return False


def check_location_is_safe(arr, row, col, num):
    return not used_in_row(arr, row, num) and not used_in_col(arr, col, num) and not used_in_box(arr, row - row % 3,
                                                                                                 col - col % 3, num)


def solve_sudoku(arr):
    record_pos = [0, 0]

    if not find_empty_location(arr, record_pos):
        return True

    row = record_pos[0]
    col = record_pos[1]

    for num in range(1, 10):

        if (check_location_is_safe(arr,
                                   row, col, num)):

            arr[row][col] = num

            if solve_sudoku(arr):
                return True

            arr[row][col] = 0

    return False


# Driver function
if __name__ == "__main__":

    # grid = [[0 for x in range(9)] for y in range(9)]

    # grid = [[3, 0, 6, 5, 0, 8, 4, 0, 0],
    #         [5, 2, 0, 0, 0, 0, 0, 0, 0],
    #         [0, 8, 7, 0, 0, 0, 0, 3, 1],
    #         [0, 0, 3, 0, 1, 0, 0, 8, 0],
    #         [9, 0, 0, 8, 6, 3, 0, 0, 5],
    #         [0, 5, 0, 0, 9, 0, 6, 0, 0],
    #         [1, 3, 0, 0, 0, 0, 2, 5, 0],
    #         [0, 0, 0, 0, 0, 0, 0, 7, 4],
    #         [0, 0, 5, 2, 0, 6, 3, 0, 0]]

    grid = [[0, 0, 9, 1, 3, 0, 6, 0, 0],
            [0, 0, 2, 5, 9, 0, 0, 0, 0],
            [0, 5, 8, 0, 6, 0, 2, 0, 0],
            [1, 0, 0, 0, 0, 7, 0, 0, 6],
            [0, 0, 0, 0, 0, 0, 0, 2, 0],
            [0, 2, 0, 0, 0, 3, 0, 7, 9],
            [4, 0, 0, 0, 0, 0, 0, 0, 5],
            [0, 7, 0, 0, 0, 0, 0, 0, 5],
            [9, 8, 1, 2, 0, 0, 0, 3, 7]]

    if solve_sudoku(grid):
        print("Solved Grid: ")
        show_grid(grid)
    else:
        print("No solution exists")
