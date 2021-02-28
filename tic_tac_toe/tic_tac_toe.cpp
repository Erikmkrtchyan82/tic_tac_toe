#include <iostream>
#include <windows.h>
using namespace std;

const char mpt = ' ';

void instruction();
void board(char*);
void ai(char*, char, char);
void human(char*, char);
char opponent(char);
char winner(char*);
bool allow(char*, int);

int main()

{
	char human_p = mpt, ai_p = mpt, move = mpt, answer = 'y';
	instruction();

	do
	{
		system("cls");
		if (answer == 'y')
		{
			do
			{
				cout << "You want to play as  'x'  or  'o' ? : ";
				cin >> human_p;
			} while (human_p != 'x' && human_p != 'o');

			system("cls");
			ai_p = opponent(human_p);
			char board_array[9] = { mpt,mpt,mpt,mpt,mpt,mpt,mpt,mpt,mpt };

			move = 'x';
			while (winner(board_array) == 'c')
			{
				if (move == human_p)
				{
					human(board_array, human_p);
				}
				else
				{
					ai(board_array, human_p, ai_p);
				}
				move = opponent(move);
			}
			if (winner(board_array) == 't')
			{
				cout << "It's a tie\n";
			}
			else
			{
				if (winner(board_array) == ai_p)
				{
					cout << "Computer win\n";
				}
				else
				{
					cout << "You win\n";
				}
			}
		}
		cout << "\nDo you want to play again (y/n)?";
		cin >> answer;
	} while (answer != 'n');
	cout << endl << endl;
}

void instruction()
{
	cout << "\t**You will choose a number between 0 and 8**\n\n";
	cout << "\n\t\t" << 0 << " | " << 1 << " | " << 2;
	cout << "\n\t\t---------";
	cout << "\n\t\t" << 3 << " | " << 4 << " | " << 5;
	cout << "\n\t\t---------";
	cout << "\n\t\t" << 6 << " | " << 7 << " | " << 8 << endl;
	cout << "\n\n\t x will start first";
	cout << "\n\n\t  **Are you ready?**\n\n\n";
	system("pause");
}
void board(char * Array)
{
	Sleep(99);
	system("cls");
	cout << "\n\t\t" << Array[0] << " | " << Array[1] << " | " << Array[2];
	cout << "\n\t\t---------";
	cout << "\n\t\t" << Array[3] << " | " << Array[4] << " | " << Array[5];
	cout << "\n\t\t---------";
	cout << "\n\t\t" << Array[6] << " | " << Array[7] << " | " << Array[8] << endl;
}
void ai(char* Array, char hum, char comp)
{
	int i = 0, k = 0;
	const int good[] = { 4,0,2,6,8,1,3,5,7 };
	do
	{
		if (allow(Array, i))
		{
			Array[i] = comp;
			if (winner(Array) == comp)
			{
				k = 1;
				break;
			}
			else
			{
				Array[i] = hum;
				if (winner(Array) == hum)
				{
					Array[i] = comp;
					k = 1;
					break;
				}
				else
				{
					Array[i] = mpt;
				}
			}
		}
		i++;
	} while (k == 0 && i < 9);

	if (k == 0)
	{
		for (int j = 0; j < 9; j++)
		{
			if (allow(Array, good[j]))
			{
				Array[good[j]] = comp;
				break;
			}
		}
	}
	board(Array);
}
void human(char* Array, char hum)
{
	int tiv = 0;
	do
	{
		cout << "Your turn : ";
		cin >> tiv;
	} while (tiv < 0 || tiv>8 || !allow(Array, tiv));
	Array[tiv] = hum;
	board(Array);
}
char opponent(char piece)
{
	if (piece == 'x')
	{
		return 'o';
	}
	return 'x';
}
char winner(char* Array)
{
	const int matrix[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	for (int i = 0; i < 8; i++)
	{
		if (Array[matrix[i][0]] != mpt &&
			Array[matrix[i][0]] == Array[matrix[i][1]] &&
			Array[matrix[i][1]] == Array[matrix[i][2]])
		{
			return Array[matrix[i][0]];
		}
	}
	if (Array[0] == mpt || Array[1] == mpt || Array[2] == mpt ||
		Array[3] == mpt || Array[4] == mpt || Array[5] == mpt ||
		Array[6] == mpt || Array[7] == mpt || Array[8] == mpt)
	{
		return 'c';
	}
	return 't';
}
bool allow(char* Array, int n)
{
	return Array[n] == mpt;
}
