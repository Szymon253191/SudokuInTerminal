/* C++ program for Sudoku generator */
#include <fstream> 
#include <cstdlib>
using namespace std;
#include <iostream> 
#include <string> 
#include <vector>

class Sudoku
{
public:
	int **mat;
	int N;

	// number of columns/rows.
	int SRN;

	// square root of N
	int K;
	// No. Of missing digits

	// Constructor
	Sudoku(int N, int K)
	{
		this->N = N;
		this->K = K;

		// Compute square root of N
		double SRNd = sqrt(N);
		SRN = (int)SRNd;
		mat = new int *[N];

		// Create a row for every pointer
		for (int i = 0; i < N; i++)
		{

			// Note : Rows may not be contiguous
			mat[i] = new int[N];

			// Initialize all entries as false to indicate
			// that there are no edges initially
			memset(mat[i], 0, N * sizeof(int));
		}
	}

	// Sudoku Generator
	void fillValues()
	{	
		// Clearing table
		clear();

		// Fill the diagonal of SRN x SRN matrices
		fillDiagonal();

		// Fill remaining blocks
		fillRemaining(0, SRN);

		// Remove Randomly K digits to make game
		removeKDigits();
	}

	// Fill the diagonal SRN number of SRN x SRN matrices
	void fillDiagonal()
	{
		for (int i = 0; i < N; i = i + SRN)
		{

			// for diagonal box, start coordinates->i==j
			fillBox(i, i);
		}
	}
	// Returns false if given 3 x 3 block contains num.
	bool unUsedInBox(int rowStart, int colStart, int num)
	{
		for (int i = 0; i < SRN; i++)
		{
			for (int j = 0; j < SRN; j++)
			{
				if (mat[rowStart + i][colStart + j] == num)
				{
					return false;
				}
			}
		}
		return true;
	}
	// Fill a 3 x 3 matrix.
	void fillBox(int row, int col)
	{
		int num;
		for (int i = 0; i < SRN; i++)
		{
			for (int j = 0; j < SRN; j++)
			{
				do
				{
					num = randomGenerator(N);
				} while (!unUsedInBox(row, col, num));
				mat[row + i][col + j] = num;
			}
		}
	}
	// Random generator
	int randomGenerator(int num)
	{
		return (int)floor(
			(float)(rand() / double(RAND_MAX) * num + 1));
	}
	// Check if safe to put in cell
	bool CheckIfSafe(int i, int j, int num)
	{
		return (
			unUsedInRow(i, num) && unUsedInCol(j, num) && unUsedInBox(i - i % SRN, j - j % SRN, num));
	}
	// check in the row for existence
	bool unUsedInRow(int i, int num)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] == num)
			{
				return false;
			}
		}
		return true;
	}
	// check in the row for existence
	bool unUsedInCol(int j, int num)
	{
		for (int i = 0; i < N; i++)
		{
			if (mat[i][j] == num)
			{
				return false;
			}
		}
		return true;
	}
	// A recursive function to fill remaining
	// matrix
	bool fillRemaining(int i, int j)
	{
		// System.out.println(i+" "+j);
		if (j >= N && i < N - 1)
		{
			i = i + 1;
			j = 0;
		}
		if (i >= N && j >= N)
		{
			return true;
		}
		if (i < SRN)
		{
			if (j < SRN)
			{
				j = SRN;
			}
		}
		else if (i < N - SRN)
		{
			if (j == (int)(i / SRN) * SRN)
			{
				j = j + SRN;
			}
		}
		else
		{
			if (j == N - SRN)
			{
				i = i + 1;
				j = 0;
				if (i >= N)
				{
					return true;
				}
			}
		}
		for (int num = 1; num <= N; num++)
		{
			if (CheckIfSafe(i, j, num))
			{
				mat[i][j] = num;
				if (fillRemaining(i, j + 1))
				{
					return true;
				}
				mat[i][j] = 0;
			}
		}
		return false;
	}
	// Remove the K no. of digits to
	// complete game
	void removeKDigits()
	{
		int count = K;
		while (count != 0)
		{
			int cellId = randomGenerator(N * N) - 1;
			// System.out.println(cellId);
			// extract coordinates i and j
			int i = (cellId / N);
			int j = cellId % 9;
			if (j != 0)
			{
				j = j - 1;
			}
			// System.out.println(i+" "+j);
			if (mat[i][j] != 0)
			{
				count--;
				mat[i][j] = 0;
			}
		}
	}
	// player inserts value into sudoku
	void insertValue()
	{
		int x, y, value;
		cout << "row, column, value. 0 = menu" << endl;
		cin >> x;
		if (x == 0)
		{
			system("CLS");
			menu();
		}
		cin >> y >> value;
		if (mat[x - 1][y - 1] != 0 || !CheckIfSafe(x - 1, y - 1, value))
		{
			cout << "Can't put value in there!" << endl;
		}
		else
		{
			cout << value << " has been put." << endl;
			mat[x - 1][y - 1] = value;
		}
	}
	// Print sudoku
	void printSudoku()
	{
		cout << "     1   2   3    4   5   6    7   8   9  " << endl;
		cout << "    === === ===  === === ===  === === === " << endl;
		for (int i = 0; i < N; i++)
		{
			cout << i+1 << " ||";
			for (int j = 0; j < N; j++)
			{
				if (mat[i][j] != 0)
				{
					cout << " " + to_string(mat[i][j]) + " ";
				}
				else
				{
					cout << "   ";
				}
				if (j % 3 == 2)
				{
					cout << "||";
				}
				else
				{
					cout << "|";
				}
			}
			cout << endl;
			if (i % 3 == 2)
			{
				cout << "    === === ===  === === ===  === === === " << endl;
			}
			else
			{
				cout << "    --- --- ---  --- --- ---  --- --- --- " << endl;
			}
		};
	}
	// menu display and selection handle
	void menu()
	{
		int option;
		cout << " ## MENU ## \n 1.Start \n 2.Continue \n 3.Exit \n";
		cin >> option;
		switch (option)
		{
		case 1:
			system("CLS");
			fillValues();
			game();
			break;
		case 2:
			system("CLS");
			/* code */
			recoverSave();
			game();
			break;
		case 3:
			system("CLS");
			exit(0);
			break;
		default:
			system("CLS");
			cout << "Wrong selection. Try again\n";
			menu();
			break;
		}
	}
	// game loop
	void game()
	{
		while (!isSolved())
		{
			// system("CLS");
			saveToFile();
			printSudoku();
			insertValue();
		}
		cout << "Congrats! You won!\n";
		system("pause");
		system("CLS");
		menu();
	}
	// check if sudoku is solved
	bool isSolved()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (mat[i][j] == 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	//savetofile
	void saveToFile()
	{
	  //Opening the file
    ofstream inputfile("save.txt", std::ofstream::trunc);
    
    if (!inputfile.is_open()) 
    cout<<"Error opening file" ;

    //Defining the loop for getting input from the file
    
    for (int r = 0; r < 9; r++) //Outer loop for rows
    {
        for (int c = 0; c < 9; c++) //inner loop for columns
        {
          inputfile << " " << mat[r][c];  //Take input from file and put into myArray
        }
    }
	}
	//recoverSave
	void recoverSave()
	{
		//Opening the file
		ifstream inputfile("save.txt");
		
		if (!inputfile.is_open()) 
		cout<<"Error opening file" ;

		//Defining the loop for getting input from the file
		
		for (int r = 0; r < 9; r++) //Outer loop for rows
		{
			for (int c = 0; c < 9; c++) //inner loop for columns
			{
			inputfile >> mat[r][c];  //Take input from file and put into myArray
			}
		}
	}
	//clearValues
	void clear()
	{
		for (int r = 0; r < 9; r++) //Outer loop for rows
    	{
			for (int c = 0; c < 9; c++) //inner loop for columns
			{
			mat[r][c] = 0;  //Take input from file and put into myArray
			}
    	}
	}
};

// Driver code
int main()
{
	int N = 9;
	int K = 2;
	srand(time(NULL));
	Sudoku *sudoku = new Sudoku(N, K);
	system("CLS");
	//sudoku->fillValues();
	//sudoku->saveToFile();
	sudoku->menu();
	return 0;
}

/* 	---------	TO DO	--------------
	- 	add functions:
		- saveToFile() 		-> saves progress of game into f.e. CSV file 								WYKONANO
		- recoverSave()		-> recovers progress from file and puts numbers into sudoku					WYKONANO
		- checkIfEnd() 		-> put into while loop in main. if true -> cout "u won" and breaks loop
		- menu() 			-> displays menu of options like: restart game, save to file, exit
	-	menu should be displayed on startup and be accessable during game.
		(f.e. if typed "menu" during game. simple 'if' checks if input is "menu"
		else game contiues)
	-	add 'if' into insertValue() to make sure player inputs number from 1-9.
	---------	DONE	--------------
	-	checkValid() not working correctly
		it allows insert wrong value into sudoku and dont sent message "error"
		DONE!!! fix: x-1, y-1 in checking function. Computer counts from 0, human from 1.
	-------- FIX PLS ------
*/

// This code is contributed by Aarti_Rathi
// and developed further by Szymon Rozmyslowski
