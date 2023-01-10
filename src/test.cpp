#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h> 

using namespace std;

#define N 9

void fillSudoku(int table[N][N])
{
    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp = rand() % 9 + 1;
            table[i][j] = temp;
        }
    }
}

void printSudoku(int table[N][N])
{
    printf("  === === ===  === === ===  === === === \n");
    for (int i = 0; i < N; i++)
    {
        printf("||");
        for (int j = 0; j < N; j++)
        {
            printf(" %d ", table[i][j]);
            if (j % 3 == 2)
            {
                printf("||");
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        if (i % 3 == 2)
        {
            printf("  === === ===  === === ===  === === === \n");
        }
        else
        {
            printf("  --- --- ---  --- --- ---  --- --- --- \n");
        }
    }
}

bool isValid(int table[N][N])
{
    // Check rows
    for (int i = 0; i < 9; i++) {
        bool is_used[9] = {false};
        for (int j = 0; j < 9; j++) {
            if (table[i][j] != 0) {
                if (is_used[table[i][j] - 1]) {
                    return false;
                }
                is_used[table[i][j] - 1] = true;
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++) {
        bool is_used[9] = {false};
        for (int i = 0; i < 9; i++) {
            if (table[i][j] != 0) {
                if (is_used[table[i][j] - 1]) {
                    return false;
                }
                is_used[table[i][j] - 1] = true;
            }
        }
    }

    // Check 3x3 sub-tables
    for (int k = 0; k < 9; k++) {
        bool is_used[9] = {false};
        for (int i = k / 3 * 3; i < k / 3 * 3 + 3; i++) {
            for (int j = (k % 3) * 3; j < (k % 3) * 3 + 3; j++) {
                if (table[i][j] != 0) {
                    if (is_used[table[i][j] - 1]) {
                        return false;
                    }
                    is_used[table[i][j] - 1] = true;
                }
            }
        }
    }

    return true;
}

int main()
{
    int sudoku[N][N]{
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    bool flag = 0;
    while(flag == 0)
    {
        srand(time(NULL));
        // fillSudoku(sudoku);
        printSudoku(sudoku);
        flag = isValid(sudoku);
        cout << flag;
        Sleep(1000);
    }
    
}