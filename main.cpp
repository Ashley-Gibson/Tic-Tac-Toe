#include <windows.h>	// For resizing console window
#include <iostream>
#include <iomanip>
#include <vector>

#include <cstdlib> // For Math Random functions

using namespace std;

// Global Variables
const char WALL = '#';
const char SPACE = ' ';
const char NOUGHT = 'O';
const char CROSS = 'X';

const int WIDTH = 13;
const int HEIGHT = 25;

int main()
{
	/* For setting Console Window Size */
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); // Stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 800, 500, TRUE); // 800 width, 100 height

	// Local Variables
	bool endGame = false;
	string turn = "Player";
	bool draw = false;
	bool quit = false;
	char restartGame = 'Y';
	char currentPlayerChar = 'X';
	char board[WIDTH][HEIGHT];
	const vector<vector<int>> gameBoardPositions = { {2, 4}, {2, 12}, {2, 20}, {6, 4}, {6, 12}, {6, 20}, {10, 4}, {10, 12}, {10, 20} };

	// Prototypes
	void initialiseBoard(char board[][HEIGHT]);
	void drawBoard(char board[][HEIGHT]);
	void getPlayerInput(char board[][HEIGHT], char currentPlayerChar);
	bool checkWinner(char board[][HEIGHT], bool& quit, char currentPlayerChar, bool& draw);
	void getAIMove(const vector<vector<int>> gameBoardPositions, char currentPlayerChar, char board[][HEIGHT]);

	while (true)
	{
		// Initialise Game
		initialiseBoard(board);

		// Update Board
		drawBoard(board);

		while (!endGame && !draw)
		{
			if (turn == "Player")
			{
				// Get Player Input
				getPlayerInput(board, currentPlayerChar);

				turn = "AI";
			}
			else if(turn == "AI")
			{
				// Get AI's Move
				getAIMove(gameBoardPositions, currentPlayerChar, board);

				turn = "Player";
			}

			// Update Board
			drawBoard(board);

			if (checkWinner(board, endGame, currentPlayerChar, draw))
			{
				break;
			}

			if (currentPlayerChar == 'X')
			{
				currentPlayerChar = 'O';
			}
			else
			{
				currentPlayerChar = 'X';
			}
		}

		if (draw)
		{
			cout << endl << endl << "Draw!" << endl << endl << "Play again? (Y): ";

			cin >> restartGame;

			if (restartGame != 'Y' && restartGame != 'y')
			{
				break;
			}
			else
			{
				draw = false;
			}
		}
		else if (turn == "AI")
		{
			cout << endl << endl << "Player 1 wins!" << endl << endl << "Play again? (Y): ";

			cin >> restartGame;

			if (restartGame != 'Y' && restartGame != 'y')
			{
				break;
			}
			else
			{
				endGame = false;
			}
		}
		else if(turn == "Player")
		{
			cout << endl << endl << "AI wins!" << endl << endl;

			cin >> restartGame;

			if (restartGame != 'Y' && restartGame != 'y')
			{
				break;
			}
			else
			{
				endGame = false;
			}
		}
	}

	//system("pause");

	return 0;
}

void initialiseBoard(char board[][HEIGHT])
{
	char boardPiece = SPACE;

	// Game Board
	for (int y = 0; y < 13; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			if (y == 0 || x == 0 || x == 8 || x == 16 || x == 24 || y == 12 || y == 4 || y == 8)
			{
				boardPiece = WALL;
			}
			else
			{
				boardPiece = SPACE;
			}

			board[y][x] = boardPiece;
		}
	}
}

void drawBoard(char board[][HEIGHT])
{
	char boardPiece = SPACE;

	// Clear the screen
	system("cls");

	// Game Board
	for (int y = 0; y < 13; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			cout << board[y][x];
		}

		cout << endl;
	}

	cout << endl << endl;
	cout << "#########################" << endl;
	cout << "#       #       #       #" << endl;
	cout << "#   1   #   2   #   3   #" << endl;	// 5,2 ; 12,2 ; 19,2
	cout << "#       #       #       #" << endl;
	cout << "#########################" << endl;
	cout << "#       #       #       #" << endl;
	cout << "#   4   #   5   #   6   #" << endl;	// 5,6 ; 12,6 ; 19,6
	cout << "#       #       #       #" << endl;
	cout << "#########################" << endl;
	cout << "#       #       #       #" << endl;
	cout << "#   7   #   8   #   9   #" << endl;	// 5,10 ; 12,10 ; 19,10
	cout << "#       #       #       #" << endl;
	cout << "#########################" << endl << endl;

	cout << "AI: O   Player 1: X" << endl << endl;
}

void getPlayerInput(char board[][HEIGHT], char currentPlayerChar)
{
	int playerInput = 0;

	cin >> playerInput;

	switch (playerInput)
	{
		case 1:
			if (board[2][4] == SPACE)
			{
				board[2][4] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 2:
			if (board[2][12] == SPACE)
			{
				board[2][12] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 3:
			if (board[2][20] == SPACE)
			{
				board[2][20] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 4:
			if (board[6][4] == SPACE)
			{
				board[6][4] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 5:
			if (board[6][12] == SPACE)
			{
				board[6][12] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 6:
			if (board[6][20] == SPACE)
			{
				board[6][20] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 7:
			if (board[10][4] == SPACE)
			{
				board[10][4] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 8:
			if (board[10][12] == SPACE)
			{
				board[10][12] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		case 9:
			if (board[10][20] == SPACE)
			{
				board[10][20] = currentPlayerChar;
			}
			else
			{
				cout << endl << "Error: Square occupied - please try again." << endl << endl;
				getPlayerInput(board, currentPlayerChar);
			}
			break;
		default:
			cout << endl << "Error: Invalid number - please type in a number between 1 and 9." << endl << endl;
			getPlayerInput(board, currentPlayerChar);
			break;
	}
}

bool checkWinner(char board[][HEIGHT], bool& endGame, char currentPlayerChar, bool& draw)
{
	// Horizontal
	if (board[2][4] == currentPlayerChar && board[2][12] == currentPlayerChar && board[2][20] == currentPlayerChar)
	{
		endGame = true;
	}
	else if (board[6][4] == currentPlayerChar && board[6][12] == currentPlayerChar && board[6][20] == currentPlayerChar)
	{
		endGame = true;
	}
	else if (board[10][4] == currentPlayerChar && board[10][12] == currentPlayerChar && board[10][20] == currentPlayerChar)
	{
		endGame = true;
	}
	// Vertical
	else if (board[2][4] == currentPlayerChar && board[6][4] == currentPlayerChar && board[10][4] == currentPlayerChar)
	{
		endGame = true;
	}
	else if (board[2][12] == currentPlayerChar && board[6][12] == currentPlayerChar && board[10][12] == currentPlayerChar)
	{
		endGame = true;
	}
	else if (board[2][20] == currentPlayerChar && board[6][20] == currentPlayerChar && board[10][20] == currentPlayerChar)
	{
		endGame = true;
	}
	// Diagonal
	else if (board[2][4] == currentPlayerChar && board[6][12] == currentPlayerChar && board[10][20] == currentPlayerChar)
	{
		endGame = true;
	}
	else if (board[2][20] == currentPlayerChar && board[6][12] == currentPlayerChar && board[10][4] == currentPlayerChar)
	{
		endGame = true;
	}
	else if (board[2][4] != SPACE && board[2][12] != SPACE && board[2][20] != SPACE && board[6][4] != SPACE && board[6][12] != SPACE && board[6][20] != SPACE && board[10][4] != SPACE && board[10][12] != SPACE && board[10][20] != SPACE)
	{
		draw = true;
	}

	return endGame;
}

void getAIMove(const vector<vector<int>> gameBoardPositions, char currentPlayerChar, char board[][HEIGHT])
{
	const int randNum = rand() % (8 - 0 + 1) + 0;

	if (board[gameBoardPositions[randNum][0]][gameBoardPositions[randNum][1]] == SPACE)
	{
		board[gameBoardPositions[randNum][0]][gameBoardPositions[randNum][1]] = currentPlayerChar;
	}
	else
	{
		getAIMove(gameBoardPositions, currentPlayerChar, board);
	}
}