#include <iostream>
#include <cmath>

using namespace std;

const int N = 9;

bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num)
            return false;

    for (int i = 0; i < N; i++)
        if (grid[i][col] == num)
            return false;

    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + boxStartRow][j + boxStartCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return true;

    if (col == N)
    {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;

            if (solveSudoku(grid, row, col + 1))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Fill in the grid with the puzzle
    // ...

    if (solveSudoku(grid, 0, 0))
    {
        cout << "Solved sudoku:" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << "| " << grid[i][j] << " | ";
            cout << endl;
        }
    }
}
