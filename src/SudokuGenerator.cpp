/* C++ program for Sudoku generator */
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

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
		cout << "row, column, value" << endl;
		cin >> x >> y >> value;
		if (mat[x - 1][y - 1] != 0 && checkValid()!=true)
		{
			cout << "Can't put value in there!" << endl;
		}
		else if (mat[x - 1][y - 1] == 0 && checkValid()==true) 
		{
			cout << value << " has been put." << endl;
			mat[x - 1][y - 1] = value;
		}
	}
	// function to check if sudoku rules are preserved
	bool checkValid()
	{
		// Check rows
		for (int i = 0; i < 9; i++)
		{
			bool is_used[9] = {false};
			for (int j = 0; j < 9; j++)
			{
				if (mat[i][j] != 0)
				{
					if (is_used[mat[i][j] - 1])
					{
						return false;
						cout << "error row" << endl;
					}
					is_used[mat[i][j] - 1] = true;
				}
			}
		}

		// Check columns
		for (int j = 0; j < 9; j++)
		{
			bool is_used[9] = {false};
			for (int i = 0; i < 9; i++)
			{
				if (mat[i][j] != 0)
				{
					if (is_used[mat[i][j] - 1])
					{
						return false;
						cout << "error col" << endl;
					}
					is_used[mat[i][j] - 1] = true;
				}
			}
		}

		// Check 3x3 sub-tables
		for (int k = 0; k < 9; k++)
		{
			bool is_used[9] = {false};
			for (int i = k / 3 * 3; i < k / 3 * 3 + 3; i++)
			{
				for (int j = (k % 3) * 3; j < (k % 3) * 3 + 3; j++)
				{
					if (mat[i][j] != 0)
					{
						if (is_used[mat[i][j] - 1])
						{
							return false;
							cout << "error 3x3" << endl;
						}
						is_used[mat[i][j] - 1] = true;
					}
				}
			}
		}
		return true;
	}
	// Print sudoku
	void printSudoku()
	{
		cout << "  === === ===  === === ===  === === === " << endl;
		for (int i = 0; i < N; i++)
		{
			cout << "||";
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
				cout << "  === === ===  === === ===  === === === " << endl;
			}
			else
			{
				cout << "  --- --- ---  --- --- ---  --- --- --- " << endl;
			}
		};
	}
};

// Driver code
int main()
{
	int N = 9;
	int K = 20;
	srand(time(NULL));
	Sudoku *sudoku = new Sudoku(N, K);
	sudoku->fillValues();
	sudoku->printSudoku();
	while (true)
	{
		sudoku->insertValue();
		bool flag = sudoku->checkValid();
		cout << flag << endl;
		sudoku->printSudoku();
	}
	return 0;
}

//  TO DO
// checkValid() not working correctly
// 	it allows insert wrong value into sudoku and dont sent message "error"



// This code is contributed by Aarti_Rathi
// and developed further by Szymon Rozmyslowski
