#include <iostream>
#include <vector>

int table[9][9];

int initializeTable(int &table, int n)
{
    //create sudoku table - full and solved
    for(int i=0;i<n;i++)
    {
        // select numbers to be put into table
    }
    return 0;
}

int printTable(int &table)
{
    // print table to terminal
    /*  EXAMPLE
      === === ===  === === ===  === === ===
    || 1 | 2 |   ||   |   | 6 || 7 | 8 | 9 ||
      --- --- ---  --- --- ---  --- --- ---
    || 1 |   | 3 || 4 | 5 | 6 ||   | 8 | 9 ||
      --- --- ---  --- --- ---  --- --- ---
    || 1 | 2 | 3 || 4 |   | 6 ||   |   | 9 ||
      === === ===  === === ===  === === ===
    || 1 |   |   || 4 | 5 | 6 || 7 |   | 9 ||
      --- --- ---  --- --- ---  --- --- ---
    || 1 |   |   || 4 | 5 | 6 ||   | 8 | 9 ||
      --- --- ---  --- --- ---  --- --- ---
    ||   | 2 | 3 || 4 |   | 6 || 7 | 8 | 9 ||
      === === ===  === === ===  === === ===
    || 1 | 2 | 3 || 4 | 5 |   ||   |   | 9 ||
      --- --- ---  --- --- ---  --- --- ---
    ||   | 2 | 3 || 4 |   |   || 7 |   | 9 ||
      --- --- ---  --- --- ---  --- --- ---
    || 1 | 2 |   ||   | 5 | 6 || 7 | 8 | 9 ||
      === === ===  === === ===  === === ===
    */
    return 0;
}

int saveGame(int &table)
{
    // save game to f.e. txt file
    return 0;
}

int recoverSave(int &table)
{
    // recover game state from save file
    return 0;
}

int inputNumber(int &table, int a, int b, int c)
{
    // input number into table. a - biq square, b - place in square, c - number to be put (from range: 1-9)
    return 0;
}

int Menu(int a)
{
    // menu where user can start new game or load game or exit
    return 0;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}