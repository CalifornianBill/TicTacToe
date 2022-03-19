#include <iostream>
#include <vector>
using namespace std;

bool menu();
void displayBoard(const vector<vector<char>>&);
void makeMove(vector<vector<char>>&, int& moveNum);
void input(vector<vector<char>>& , pair<int, int>&);
char winDetect(const vector<vector<char>>&, int moveNum);

int main()
{
	vector<vector<char>> board(3, vector<char>(3, ' '));
	bool end = menu();

	while (!end) {
		int moveNum = 0;
		bool noWinner = true;

		displayBoard(board);

		while (noWinner) {

			makeMove(board, moveNum);

			displayBoard(board);

			//Win Detection
			char winner = winDetect(board, moveNum);
			if (winner != ' ') {
				cout << winner << " Wins!\n\n";
				noWinner = false;
			}
		}
		end = menu();
	}
}

bool menu() {
	int choice = 0;
	cout << "Tic Tac Toe\n1. New Game\n2. Exit\n3. Credits\n";
	cin >> choice;
	while (true) {
		switch (choice) {
			case 1:
				return false;
			case 2:
				return true;
			case 3:
				cout << "----------------------------\n";
				cout << "|\tTic Tac Toe\t   |\n|Programmed By Chase Elsea |\n|\t3-19-2022\t   |\n";
				cout << "----------------------------\n\n";
				cout << "Enter a new option to continue\n";
				cin >> choice;
				break;
			default:
				cout << "Invalid Choice\n";
				cin >> choice;
		}
	}
}

void displayBoard(const vector<vector<char>>& board) {
	cout << "-------" << endl;
	for (auto y: board) {
		cout << "|" << y[0] << "|" << y[1] << "|" << y[2] << "|" << endl;
		cout << "-------" << endl;
	}
}

void makeMove(vector<vector<char>>& board, int& moveNum) {
		pair<int, int> coord;
		if (moveNum % 2 == 0) {
			cout << "Player X Turn\n";
			input(board, coord);
			board[3-coord.second][coord.first-1] = 'X';
			++moveNum;
		}
		else if (moveNum % 2 == 1) {
			cout << "Player O Turn\n";
			input(board,  coord);
			board[3-coord.second][coord.first-1] = 'O';
			++moveNum;
		}
}

void input(vector<vector<char>>& board, pair<int, int>& coord) {
	cout << "Enter \"x y\"\n";
	cin >> coord.first >> coord.second;
	while (true) {
		if (coord.first > 3 || coord.first < 1 || coord.second > 3 || coord.second < 1) {
			cout << "Out Of Bounds\n Enter \"x y\"\n";
			cin >> coord.first >> coord.second;
		}
		if (board[3 - coord.second][coord.first - 1] != ' ') {
			cout << "Illegal Move\n Enter \"x y\"\n";
			cin >> coord.first >> coord.second;
		}
		else break;
	}
}

char winDetect(const vector<vector<char>>& board, int moveNum) {
	if (moveNum > 2) {
		for (int i = 0; i < 3; ++i) {
			if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
				return board[i][0];
		}
		for (int x = 0; x < 3; ++x) {
			if (board[0][x] == board[1][x] && board[0][x] == board[2][x])
				return board[0][x];
		}
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
			return board[0][0];
		if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
			return board[2][0];
	}
	return ' ';
}