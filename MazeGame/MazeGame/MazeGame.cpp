#include <iostream>
#include <windows.h>
#include <conio.h> //For _getch usage
#include <string> //For string methods
using namespace std;

// #define is used to allow us to give a name to a constant value before the program is compiled
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

struct CELL {
	int playerY = 1;
	int playerX = 0;
	bool isVisited = false;
	bool isWall = false;
	bool isPlayer = false;
};
CELL playerCord;

void menu(string arrow, int arrowPos) {

	cout << "*--------------------------------------*" << endl;
	cout << ":                                      :" << endl;
	cout << ":  __   __  _______  _______  _______  :" << endl;
	cout << ": |  |_|  ||   _   ||       ||       | :" << endl;
	cout << ": |       ||  |_|  ||____   ||    ___| :" << endl;
	cout << ": |       ||       | ____|  ||   |___  :" << endl;
	cout << ": |       ||       || ______||    ___| :" << endl;
	cout << ": | ||_|| ||   _   || |_____ |   |___  :" << endl;
	cout << ": |_|   |_||__| |__||_______||_______| :" << endl;
	cout << ":                                      :" << endl;
	cout << ":                                      :" << endl;
	if (arrowPos == 0)
		cout << ":            " << arrow << "  Play                 :" << endl;
	else
		cout << ":                 Play                 :" << endl;
	cout << ":                                      :" << endl;
	if (arrowPos == 1)
		cout << ":            " << arrow << "  Options              :" << endl;
	else
		cout << ":                 Options              :" << endl;
	cout << ":                                      :" << endl;
	if (arrowPos == 2)
		cout << ":            " << arrow << "  Exit                 :" << endl;
	else
		cout << ":                 Exit                 :" << endl;
	cout << ":                                      :" << endl;
	cout << ":     Use Space or Enter to choose     :" << endl;
	cout << ":                                      :" << endl;
	cout << "*--------------------------------------*" << endl;
}

int chooseMenu(string arrow, int arrowPos) {
	bool choose = true;
	while (1) {
		menu(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				system("cls");
				return 0;
			}
			else if (arrowPos == 2) {
				exit(0);
			}
			break;
		case KEY_UP:
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
			if (arrowPos != 2)
				arrowPos++;
			break;
		}
		system("cls");
	}
}

void difficulty(string arrow, int arrowPos) {
	cout << "*--------------------------------------------------------------------------------------*" << endl;
	cout << ":                                                                                      :" << endl;
	cout << ":  ______   ___   _______  _______  ___   _______  __   __  ___      _______  __   __  :" << endl;
	cout << ": |      | |   | |       ||       ||   | |       ||  | |  ||   |    |       ||  | |  | :" << endl;
	cout << ": |  _    ||   | |    ___||    ___||   | |       ||  | |  ||   |    |_     _||  |_|  | :" << endl;
	cout << ": | | |   ||   | |   |___ |   |___ |   | |       ||  |_|  ||   |      |   |  |       | :" << endl;
	cout << ": | |_|   ||   | |    ___||    ___||   | |      _||       ||   |___   |   |  |_     _| :" << endl;
	cout << ": |       ||   | |   |    |   |    |   | |     |_ |       ||       |  |   |    |   |   :" << endl;
	cout << ": |______| |___| |___|    |___|    |___| |_______||_______||_______|  |___|    |___|   :" << endl;
	cout << ":                                                                                      :" << endl;
	cout << ":                                                                                      :" << endl;
	if (arrowPos == 0)
		cout << ":                                    " << arrow << "  Easy                                         :" << endl;
	else
		cout << ":                                         Easy                                         :" << endl;
	cout << ":                                                                                      :" << endl;
	if (arrowPos == 1)
		cout << ":                                    " << arrow << "  Normal                                       :" << endl;
	else
		cout << ":                                         Normal                                       :" << endl;
	cout << ":                                                                                      :" << endl;
	if (arrowPos == 2)
		cout << ":                                    " << arrow << "  Hard                                         :" << endl;
	else
		cout << ":                                         Hard                                         :" << endl;
	cout << ":                                                                                      :" << endl;
	cout << ":                             Use Space or Enter to choose                             :" << endl;
	cout << ":                                                                                      :" << endl;
	cout << "*--------------------------------------------------------------------------------------*" << endl;
}

int chooseDifficulty(string arrow, int arrowPos, int* size) {
	while (1) {
		difficulty(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				*size = 3;
				return 0;
			}
			else if (arrowPos == 1) {
				*size = 7;
				return 0;
			}
			else if (arrowPos == 2) {
				*size = 15;
				return 0;
			}
			break;
		case KEY_UP:
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
			if (arrowPos != 2)
				arrowPos++;
			break;
		}
		system("cls");
	}
}

// this function generates the maze,by previously entered size
void printMaze(CELL** maze, int size, char free, char player) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (maze[i][j].isPlayer == true) {
				cout << player << " ";
			}
			else if (maze[i][j].isVisited == true) {
				cout << free << " ";
			}
			else {
				cout << char(254) << " ";
			}
		}
		cout << endl;
	}
}

// this function generates the walls of the maze
void createWalls(CELL** maze, int size, int* cellCount) {
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if ((x % 2 == 0) || (y % 2 == 0)) {
				maze[y][x].isWall = true;
			}
			else {
				++* cellCount;
			}
		}
	}
}

void toVisited(CELL** maze, int* cordY, int* cordX, int dir, int* unvisitedCells) {
	switch (dir) {
	case 0:
		if (maze[*cordY - 2][*cordX].isVisited == false) {
			maze[*cordY - 2][*cordX].isVisited = true;
			maze[*cordY - 2][*cordX].isWall = false;
			maze[*cordY - 1][*cordX].isVisited = true;
			maze[*cordY - 1][*cordX].isWall = false;
			++* unvisitedCells;
		}
		*cordY -= 2;
		break;
	case 1:
		if (maze[*cordY][*cordX + 2].isVisited == false) {
			maze[*cordY][*cordX + 2].isVisited = true;
			maze[*cordY][*cordX + 2].isWall = false;
			maze[*cordY][*cordX + 1].isVisited = true;
			maze[*cordY][*cordX + 1].isWall = false;
			++* unvisitedCells++;
		}
		*cordX += 2;
		break;
	case 2:
		if (maze[*cordY + 2][*cordX].isVisited == false) {
			maze[*cordY + 2][*cordX].isVisited = true;
			maze[*cordY + 2][*cordX].isWall = false;
			maze[*cordY + 1][*cordX].isVisited = true;
			maze[*cordY + 1][*cordX].isWall = false;
			++* unvisitedCells++;
		}
		*cordY += 2;
		break;
	case 3:
		if (maze[*cordY][*cordX - 2].isVisited == false) {
			maze[*cordY][*cordX - 2].isVisited = true;
			maze[*cordY][*cordX - 2].isWall = false;
			maze[*cordY][*cordX - 1].isVisited = true;
			maze[*cordY][*cordX - 1].isWall = false;
			++* unvisitedCells++;
		}
		*cordX -= 2;
		break;
	}
}

// this function checks if the player is trying to move towards a wall
void playerMovement(CELL** maze) {
	switch (_getch()) {
	case KEY_UP:
	case 119:
	case 87:
		if (maze[playerCord.playerY - 1][playerCord.playerX].isWall == false) {
			maze[playerCord.playerY][playerCord.playerX].isPlayer = false;
			playerCord.playerY -= 1;
			maze[playerCord.playerY][playerCord.playerX].isPlayer = true;
		}
		else {
			cout << endl;
			cout << "Can't move there!";
			if (_getch()) return;
		}
		break;
	case KEY_DOWN:
	case 115:
	case 83:
		if (maze[playerCord.playerY + 1][playerCord.playerX].isWall == false) {
			maze[playerCord.playerY][playerCord.playerX].isPlayer = false;
			playerCord.playerY += 1;
			maze[playerCord.playerY][playerCord.playerX].isPlayer = true;
		}
		else {
			cout << endl;
			cout << "Can't move there!";
			if (_getch()) return;
		}
		break;
	case KEY_LEFT:
	case 97:
	case 65:
		if (maze[playerCord.playerY][playerCord.playerX - 1].isWall == false) {
			maze[playerCord.playerY][playerCord.playerX].isPlayer = false;
			playerCord.playerX -= 1;
			maze[playerCord.playerY][playerCord.playerX].isPlayer = true;
		}
		else {
			cout << endl;
			cout << "Can't move there!";
			if (_getch()) return;
		}
		break;
	case KEY_RIGHT:
	case 100:
	case 68:
		if (maze[playerCord.playerY][playerCord.playerX + 1].isWall == false) {
			maze[playerCord.playerY][playerCord.playerX].isPlayer = false;
			playerCord.playerX += 1;
			maze[playerCord.playerY][playerCord.playerX].isPlayer = true;
		}
		else {
			cout << endl;
			cout << "Can't move there!";
			if(_getch()) return;
		}
		break;
	}
}

bool freeCheck(int dir, int size, int cordY, int cordX) {
	return (dir == 0 && cordY == 1) or
		(dir == 2 && cordY == size - 2) or
		(dir == 1 && cordX == size - 2) or
		(dir == 3 && cordX == 1);
}

//prints Winning text
void winningText() {
	cout << "*---------------------------------------------*" << endl;
	cout << "|   __     __                    _       _    |\n"
		"|   \\ \\   / /                   (_)     | |   |\n"
		"|    \\ \\_/ /__  _   _  __      ___ _ __ | |   |\n"
		"|     \\   / _ \\| | | | \\ \\ /\\ / / | '_ \\| |   |\n"
		"|      | | (_) | |_| |  \\ V  V /| | | | |_|   |\n"
		"|      |_|\\___/ \\__,_|   \\_/ \\_/|_|_| |_(_)   |\n";
	cout << "*---------------------------------------------*" << endl;
}

// this is the main function
int main() {
	system("color 5");
	srand((unsigned int)time(NULL));

	int cordY, cordX = 1;
	int cellCount = 0;
	char free = ' ';
	char player = char(2);
	int size;
	string arrow = "-->";
	int arrowPos = 0;

	chooseMenu(arrow, arrowPos);
	chooseDifficulty(arrow, arrowPos, &size);
	system("cls");

	cout << endl;
	cout << "Good, luck!" << endl;
	cout << "*---------*" << endl;
	cout << endl;

	cordY = 1;

	size = size * 2 + 1;

	CELL** maze = new CELL * [size];
	for (int i = 0; i < size; i++) {
		maze[i] = new CELL[size];
	}

	maze[cordY][cordX - 1].isPlayer = true;
	maze[cordY][cordX - 1].isVisited = true;
	maze[size - 2][size - 1].isVisited = true;

	createWalls(maze, size, &cellCount);

	maze[cordY][cordX - 1].isWall = false;
	maze[size - 2][size - 1].isWall = false;

	bool unvisitedCheck = true;
	int unvisitedCells = 0;

	while (unvisitedCheck) {
		if (unvisitedCells == cellCount) {
			unvisitedCheck = false;
		}
		int dir;
		do {
			dir = rand() % 4;
		} while (freeCheck(dir, size, cordY, cordX));

		toVisited(maze, &cordY, &cordX, dir, &unvisitedCells);
	}

	bool playerWon = true;
	while (playerWon) {
		if (maze[size - 2][size - 1].isPlayer == true) {
			system("cls");
			winningText();
			exit(0);
		}
		printMaze(maze, size, free, player);
		cout << "\n";
		cout << "*--------------------------*" << endl;
		cout << "|                          |" << endl;
		cout << "|       Instructions:      |" << endl;
		cout << "|    Use the arrows or     |" << endl;
		cout << "|         W,A,S,D          |" << endl;
		cout << "|                          |" << endl;
		cout << "*--------------------------*";
		playerMovement(maze);
		system("cls");
	}
}