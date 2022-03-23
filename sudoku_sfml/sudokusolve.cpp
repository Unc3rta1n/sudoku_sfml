#include "sudokusolve.hpp"

int isAvailable(int solution[][9], int row, int col, int num)
{
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;


    for (int i = 0; i < 9; ++i)
    {
        if (solution[row][i] == num) return 0;
        if (solution[i][col] == num) return 0;
        if (solution[rowStart + (i % 3)][colStart + (i / 3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int solution[][9], int row, int col) {
    int i;
    if (row < 9 && col < 9)
    {
        if (solution[row][col] != 0)
        {
            if ((col + 1) < 9) return fillSudoku(solution, row, col + 1);
            else if ((row + 1) < 9) return fillSudoku(solution, row + 1, 0);
            else return 1;
        }
        else
        {
            for (i = 0; i < 9; ++i)
            {
                if (isAvailable(solution, row, col, i + 1))
                {
                    solution[row][col] = i + 1;
                    if ((col + 1) < 9)
                    {
                        if (fillSudoku(solution, row, col + 1)) return 1;
                        else solution[row][col] = 0;
                    }
                    else if ((row + 1) < 9)
                    {
                        if (fillSudoku(solution, row + 1, 0)) return 1;
                        else solution[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}