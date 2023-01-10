#include <iostream>
#include <vector>
using namespace std;

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

void printTable()
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
   
   cout <<"  === === ===  === === ===  === === ===  " << endl;
   cout <<"|| "<<table[0][0]<<" | "<<table[0][1]<<" | "<<table[0][2]<<" || "<<table[0][3]<<" | "<<table[0][4]<<" | "<<table[0][5]<<" || "<<table[0][6]<<" | "<<table[0][7]<<" | "<<table[0][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[1][0]<<" | "<<table[1][1]<<" | "<<table[1][2]<<" || "<<table[1][3]<<" | "<<table[1][4]<<" | "<<table[1][5]<<" || "<<table[1][6]<<" | "<<table[1][7]<<" | "<<table[1][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[2][0]<<" | "<<table[2][1]<<" | "<<table[2][2]<<" || "<<table[2][3]<<" | "<<table[2][4]<<" | "<<table[2][5]<<" || "<<table[2][6]<<" | "<<table[2][7]<<" | "<<table[2][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[3][0]<<" | "<<table[3][1]<<" | "<<table[3][2]<<" || "<<table[3][3]<<" | "<<table[3][4]<<" | "<<table[3][5]<<" || "<<table[3][6]<<" | "<<table[3][7]<<" | "<<table[3][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[4][0]<<" | "<<table[4][1]<<" | "<<table[4][2]<<" || "<<table[4][3]<<" | "<<table[4][4]<<" | "<<table[4][5]<<" || "<<table[4][6]<<" | "<<table[4][7]<<" | "<<table[4][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[5][0]<<" | "<<table[5][1]<<" | "<<table[5][2]<<" || "<<table[5][3]<<" | "<<table[5][4]<<" | "<<table[5][5]<<" || "<<table[5][6]<<" | "<<table[5][7]<<" | "<<table[5][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[6][0]<<" | "<<table[6][1]<<" | "<<table[6][2]<<" || "<<table[6][3]<<" | "<<table[6][4]<<" | "<<table[6][5]<<" || "<<table[6][6]<<" | "<<table[6][7]<<" | "<<table[6][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[7][0]<<" | "<<table[7][1]<<" | "<<table[7][2]<<" || "<<table[7][3]<<" | "<<table[7][4]<<" | "<<table[7][5]<<" || "<<table[7][6]<<" | "<<table[7][7]<<" | "<<table[7][8]<<" || "<< endl;
   cout <<"  --- --- ---  --- --- ---  --- --- ---  " << endl;
   cout <<"|| "<<table[8][0]<<" | "<<table[8][1]<<" | "<<table[8][2]<<" || "<<table[8][3]<<" | "<<table[8][4]<<" | "<<table[8][5]<<" || "<<table[8][6]<<" | "<<table[8][7]<<" | "<<table[8][8]<<" || "<< endl;
   cout <<"  === === ===  === === ===  === === ===  " << endl;
   
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
    printTable();
    return 0;
}