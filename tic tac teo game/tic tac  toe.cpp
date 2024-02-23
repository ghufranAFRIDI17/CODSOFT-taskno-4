#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
const int size = 9;
char board[size];
void set_default_board()
{
	for (int i = 0; i < size; ++i)
		board[i] = ' ';
}
void print()
{

	for (int i = 0; i < size;)
	{
		cout << "   ----------- ----------- -----------  " << endl;
		cout << "  |           |           |           |" << endl;
		cout << "  |     ";
		for (int j = 0; j < size/3; ++j,++i)
		{
			if (board[i] != ' ')
			{
				cout << board[i] << "     |     ";
			}
			else
			{
				cout << "(" << i + 1 << ")   |     ";

			}
		}
		cout << endl << "  |           |           |           |" << endl;
	}
	cout << "   ----------- ----------- -----------  " << endl << endl;

}
int check_status()
{
	int draw = 3;
	for (int x = 0; x < size / 3; ++x)
	{
		if (board[x] == board[x + 3] && board[x] == board[x + 6])
		{
			if (board[x] == 'X')
				return 1;
			else if (board[x] == 'O')
				return 2;
			draw = 0;
		}
		else if (board[x] == ' ' || board[x + 3] == ' ' || board[x + 6] == ' ')
		{
			draw = 0;
		}
	}
	for (int x = 0; x < size; x+=3)
	{
		if (board[x] == board[x + 1] && board[x] == board[x + 2])
		{
			if (board[x] == 'X')
				return 1;
			else if (board[x] == 'O')
				return 2;
			draw = 0;
		}
		else if (board[x] == ' ' || board[x + 1] == ' ' || board[x + 2] == ' ')
		{
			draw = 0;
		}
	}
	if (board[0] == board[4] && board[0] == board[8])
	{
		if (board[4] == 'X')
			return 1;
		else if (board[4] == 'O')
			return 2;
		draw = 0;
	}
	if (board[2] == board[4] && board[2] == board[6])
	{
		if (board[4] == 'X')
			return 1;
		else if (board[4] == 'O')
			return 2;
		draw = 0;
	}
	return draw;
}
int main()
{

	string option;
	while (true)
	{
		system("CLS");
		bool flag = 0;
		int index, status = 0;
		set_default_board();
		print();
		while (status == 0)
		{
			if (flag == 0)
			{
				cout << "Player1(X),Enter index:";
			}
			else
			{
				cout << "Player2(O),Enter index:";
			}
			string ind;
			getline(cin, ind);
			while (ind.length() > 1)
			{
				cout << "Invalid input, Enter Again (1,2,3,4,5,6,7,8,9) :";
				getline(cin, ind);
			}
			index = ind[0] - '0';
			index -= 1;
			if (board[index] == ' ')
			{
				if (flag == 0)
					board[index] = 'X';
				else
					board[index] = 'O';
				flag = !flag;
				system("CLS");
				print();
				status = check_status();
				continue;
			}
			cout << "You have selected Invalid index, Enter Again." << endl;
		}
		if (status == 1)
		{
			cout << "Player1 (X) Wins" << endl;
		}
		else if (status == 2)
		{
			cout << "Player2 (O) Wins" << endl;
		}
		else
		{
			cout << "Match Draw" << endl;
		}

		cout << "Do you want to play again ?" << endl;
		cout << "Enter Yes/No :";
		getline(cin, option);
		if (option.compare("Yes") == 0 || option.compare("yes") == 0 || option.compare("YES") == 0)
		{
			continue;
		}
		else if (option.compare("No") == 0 || option.compare("no") == 0 || option.compare("NO") == 0)
		{
			break;
		}
		else
		{
			while (option.compare("Yes") != 0 && option.compare("yes") != 0 && option.compare("YES") != 0 && option.compare("No") != 0 && option.compare("no") != 0 && option.compare("NO") != 0)
			{
				cout << "You have Enter Invalid Option,Try again :";
				getline(cin, option);
			}
		}
	}

	cout << "Program Finished" << endl;


	return 0;
}