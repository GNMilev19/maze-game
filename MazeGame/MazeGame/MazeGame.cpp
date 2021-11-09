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

//Prints Main menu
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

//Prints Options menu
void options(string arrow, int arrowPos) {
	cout << "*--------------------------------------------------------------*" << endl;
	cout << ":                                                              :" << endl;
	cout << ":  _______  _______  _______  ___   _______  __    _  _______  :" << endl;
	cout << ": |       ||       ||       ||   | |       ||  |  | ||       | :" << endl;
	cout << ": |   _   ||    _  ||_     _||   | |   _   ||   |_| ||  _____| :" << endl;
	cout << ": |  | |  ||   |_| |  |   |  |   | |  | |  ||       || |_____  :" << endl;
	cout << ": |  |_|  ||    ___|  |   |  |   | |  |_|  ||  _    ||_____  | :" << endl;
	cout << ": |       ||   |      |   |  |   | |       || | |   | _____| | :" << endl;
	cout << ": |_______||___|      |___|  |___| |_______||_|  |__||_______| :" << endl;
	cout << ":                                                              :" << endl;
	cout << ":                                                              :" << endl;
	if (arrowPos == 0)
		cout << ":                       " << arrow << "  Color                             :" << endl;
	else
		cout << ":                            Color                             :" << endl;
	cout << ":                                                              :" << endl;
	if (arrowPos == 1)
		cout << ":                       " << arrow << "  Character                         :" << endl;
	else
		cout << ":                            Character                         :" << endl;
	cout << ":                                                              :" << endl;
	if (arrowPos == 2)
		cout << ":                       " << arrow << "  Back                              :" << endl;
	else
		cout << ":                            Back                              :" << endl;
	cout << ":                                                              :" << endl;
	cout << ":                  Use Space or Enter to choose                :" << endl;
	cout << ":                                                              :" << endl;
	cout << "*--------------------------------------------------------------*" << endl;
}

//Prints Color Options menu
void colorMenu(string arrow, int arrowPos) {
	cout << "*---------------------------------------------------------*" << endl;
	cout << ":                                                         :" << endl;
	cout << ":  _______  _______  ___      _______  ______    _______  :" << endl;
	cout << ": |       ||       ||   |    |       ||    _ |  |       | :" << endl;
	cout << ": |       ||   _   ||   |    |   _   ||   | ||  |  _____| :" << endl;
	cout << ": |       ||  | |  ||   |    |  | |  ||   |_||_ | |_____  :" << endl;
	cout << ": |      _||  |_|  ||   |___ |  |_|  ||    __  ||_____  | :" << endl;
	cout << ": |     |_ |       ||       ||       ||   |  | | _____| | :" << endl;
	cout << ": |_______||_______||_______||_______||___|  |_||_______| :" << endl;
	cout << ":                                                         :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 0)
		cout << ":                     " << arrow << "  Aqua                           :" << endl;
	else
		cout << ":                          Aqua                           :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 1)
		cout << ":                     " << arrow << "  Green                          :" << endl;
	else
		cout << ":                          Green                          :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 2)
		cout << ":                     " << arrow << "  Red                            :" << endl;
	else
		cout << ":                          Red                            :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 3)
		cout << ":                     " << arrow << "  Purple                         :" << endl;
	else
		cout << ":                          Purple                         :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 4)
		cout << ":                     " << arrow << "  White                          :" << endl;
	else
		cout << ":                          White                          :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 5)
		cout << ":                     " << arrow << "  Back                           :" << endl;
	else
		cout << ":                          Back                           :" << endl;
	cout << ":                                                         :" << endl;
	cout << ":                  Use Space or Enter to choose           :" << endl;
	cout << ":                                                         :" << endl;
	cout << "*-------------------------------------------------------------*" << endl;
}

//Used to choose color option
int chooseColor(string arrow, int arrowPos) {
	arrowPos = 0;
	while (1) {
		colorMenu(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				system("color 3");
			}
			else if (arrowPos == 1) {
				system("color 2");
			}
			else if (arrowPos == 2) {
				system("color 4");
			}
			else if (arrowPos == 3) {
				system("color 5");
			}
			else if (arrowPos == 4) {
				system("color 7");
			}
			else if (arrowPos == 5) {
				system("cls");
				return 0;
			}
			break;
		case KEY_UP:
		case 'W':
		case 'w':
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
		case 'S':
		case 's':
			if (arrowPos != 5)
				arrowPos++;
			break;
		}
		system("cls");
	}
}

//Prints Character Options menu
void characterMenu(string arrow, int arrowPos) {
	cout << "*-------------------------------------------------------------------------------------*" << endl;
	cout << ":                                                                                     :" << endl;
	cout << ":  _______  __   __  _______  ______    _______  _______  _______  _______  ______    :" << endl;
	cout << ": |       ||  | |  ||   _   ||    _ |  |   _   ||       ||       ||       ||    _ |   :" << endl;
	cout << ": |       ||  |_|  ||  |_|  ||   | ||  |  |_|  ||       ||_     _||    ___||   | ||   :" << endl;
	cout << ": |       ||       ||       ||   |_||_ |       ||       |  |   |  |   |___ |   |_||_  :" << endl;
	cout << ": |      _||       ||       ||    __  ||       ||      _|  |   |  |    ___||    __  | :" << endl;
	cout << ": |     |_ |   _   ||   _   ||   |  | ||   _   ||     |_   |   |  |   |___ |   |  | | :" << endl;
	cout << ": |_______||__| |__||__| |__||___|  |_||__| |__||_______|  |___|  |_______||___|  |_| :" << endl;
	cout << ":                                                                                     :" << endl;
	cout << ":                                                                                     :" << endl;
	if (arrowPos == 0)
		cout << ":                                      " << arrow << "  " << char(1) << "                                         :" << endl;
	else
		cout << ":                                           " << char(1) << "                                         :" << endl;
	cout << ":                                                                                     :" << endl;
	if (arrowPos == 1)
		cout << ":                                      " << arrow << "  " << char(2) << "                                         :" << endl;
	else
		cout << ":                                           " << char(2) << "                                         :" << endl;
	cout << ":                                                                                     :" << endl;
	if (arrowPos == 2)
		cout << ":                                      " << arrow << "  " << char(3) << "                                         :" << endl;
	else
		cout << ":                                           " << char(3) << "                                         :" << endl;
	cout << ":                                                                                     :" << endl;
	if (arrowPos == 3)
		cout << ":                                      " << arrow << "  " << char(4) << "                                         :" << endl;
	else
		cout << ":                                           " << char(4) << "                                         :" << endl;
	cout << ":                                                                                     :" << endl;
	if (arrowPos == 4)
		cout << ":                                      " << arrow << "  " << char(5) << "                                         :" << endl;
	else
		cout << ":                                           " << char(5) << "                                         :" << endl;
	cout << ":                                                                                     :" << endl;
	if (arrowPos == 5)
		cout << ":                                      " << arrow << "  " << char(6) << "                                         :" << endl;
	else
		cout << ":                                           " << char(6) << "                                         :" << endl;
	cout << ":                                                                                     :" << endl;
	if (arrowPos == 6)
		cout << ":                                      " << arrow << "  Back                                      :" << endl;
	else
		cout << ":                                           Back                                      :" << endl;
	cout << ":                                                                                     :" << endl;
	cout << ":                                Use Space or Enter to choose                         :" << endl;
	cout << ":                                                                                     :" << endl;
	cout << "*-------------------------------------------------------------------------------------*" << endl;
}

//Used for chosing character symbol menu
int chooseCharacter(string arrow, int arrowPos, char* playerSym) {
	arrowPos = 0;
	while (1) {
		characterMenu(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				*playerSym = char(1);
			}
			else if (arrowPos == 1) {
				*playerSym = char(2);
			}
			else if (arrowPos == 2) {
				*playerSym = char(3);
			}
			else if (arrowPos == 3) {
				*playerSym = char(4);
			}
			else if (arrowPos == 4) {
				*playerSym = char(5);
			}
			else if (arrowPos == 5) {
				*playerSym = char(6);
			}
			else if (arrowPos == 6) {
				system("cls");
				return 0;
			}
			break;
		case KEY_UP:
		case 'W':
		case 'w':
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
		case 'S':
		case 's':
			if (arrowPos != 6)
				arrowPos++;
			break;
		}
		system("cls");
	}
}

//Used for choosing which option to change
int chooseOptions(string arrow, int arrowPos, char* playerSym) {
	arrowPos = 0;
	while (1) {
		options(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				system("cls");
				chooseColor(arrow, arrowPos);
				arrowPos = 0;
			}
			else if (arrowPos == 1) {
				system("cls");
				chooseCharacter(arrow, arrowPos, playerSym);
				arrowPos = 0;
			}
			else if (arrowPos == 2) {
				system("cls");
				return 0;
			}
			break;
		case KEY_UP:
		case 'W':
		case 'w':
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
		case 'S':
		case 's':
			if (arrowPos != 2)
				arrowPos++;
			break;
		}
		system("cls");
	}
}

//Prints Difficulty menu
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
	if (arrowPos == 3)
		cout << ":                                    " << arrow << "  Custom                                       :" << endl;
	else
		cout << ":                                         Custom                                       :" << endl;
	cout << ":                                                                                      :" << endl;
	cout << ":                             Use Space or Enter to choose                             :" << endl;
	cout << ":                                                                                      :" << endl;
	cout << "*--------------------------------------------------------------------------------------*" << endl;
}

//Used for choosing Game Difficulty
int chooseDifficulty(string arrow, int arrowPos, int* size) {
	while (1) {
		difficulty(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				*size = 7;
				return 0;
			}
			else if (arrowPos == 1) {
				*size = 15;
				return 0;
			}
			else if (arrowPos == 2) {
				*size = 20;
				return 0;
			}
			else if (arrowPos == 3) {
				cout << "Please, input maze size: ";
				cin >> *size;
				return 0;
			}
			break;
		case KEY_UP:
		case 'W':
		case 'w':
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
		case 'S':
		case 's':
			if (arrowPos != 3)
				arrowPos++;
			break;
		}
		system("cls");
	}
}

//Choose whether to Play, change Options or Exit
int chooseMenu(string arrow, int arrowPos, int* size, char* playerSym) {
	while (1) {
		menu(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				system("cls");
				chooseDifficulty(arrow, arrowPos, size);
				switch (arrowPos) {
				case 3: arrowPos = 0; break;
				default: return 0; break;
				}
			}
			else if (arrowPos == 1) {
				system("cls");
				chooseOptions(arrow, arrowPos, playerSym);
				arrowPos = 0;
			}
			else if (arrowPos == 2) {
				exit(0);
			}
			break;
		case KEY_UP:
		case 'W':
		case 'w':
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
		case 'S':
		case 's':
			if (arrowPos != 2)
				arrowPos++;
			break;
		}
		system("cls");
	}
}

// this function generates the maze,by previously entered size
void printMaze(CELL** maze, int size, char free, char playerSym) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (maze[i][j].isPlayer == true) {
				cout << playerSym << " ";
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

//make cell into free cells
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
		break;
	case KEY_DOWN:
	case 115:
	case 83:
		if (maze[playerCord.playerY + 1][playerCord.playerX].isWall == false) {
			maze[playerCord.playerY][playerCord.playerX].isPlayer = false;
			playerCord.playerY += 1;
			maze[playerCord.playerY][playerCord.playerX].isPlayer = true;
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
		break;
	case KEY_RIGHT:
	case 100:
	case 68:
		if (maze[playerCord.playerY][playerCord.playerX + 1].isWall == false) {
			maze[playerCord.playerY][playerCord.playerX].isPlayer = false;
			playerCord.playerX += 1;
			maze[playerCord.playerY][playerCord.playerX].isPlayer = true;
		}
		break;
	}
}

//check if next cell is not a border
bool freeCheck(int dir, int size, int cordY, int cordX) {
	return (dir == 0 && cordY == 1) or
		(dir == 2 && cordY == size - 2) or
		(dir == 1 && cordX == size - 2) or
		(dir == 3 && cordX == 1);
}

//prints Winning text
void winningText() {
	cout << "*-----------------------------------------------------------*" << endl;
	cout << "|  __   __  _______  __   __    _     _  ___   __    _  __  |" << endl;
	cout << "| |  | |  ||       ||  | |  |  | | _ | ||   | |  |  | ||  | |" << endl;
	cout << "| |  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| ||  | |" << endl;
	cout << "| |       ||  | |  ||  |_|  |  |       ||   | |       ||  | |" << endl;
	cout << "| |_     _||  |_|  ||       |  |       ||   | |  _    ||__| |" << endl;
	cout << "|   |   |  |       ||       |  |   _   ||   | | | |   | __  |" << endl;
	cout << "|   |___|  |_______||_______|  |__| |__||___| |_|  |__||__| |" << endl;
	cout << "*-----------------------------------------------------------*" << endl;
}

// this is the main function
int main() {
	srand((unsigned int)time(NULL)); //To give us different random numbers every time

	int cordY, cordX;
	int cellCount = 0;
	char free = ' ';
	char playerSym = char(1); //
	int size;
	string arrow = "-->";
	int arrowPos = 0;
	
	while (1) {
		chooseMenu(arrow, arrowPos, &size, &playerSym);
		system("cls");

		cout << endl;
		cout << "Good, luck!" << endl;
		cout << "*---------*" << endl;
		cout << endl;

		cordY = 1;
		cordX = 1;
		cellCount = 0;

		size = size * 2 + 1;

		CELL** maze = new CELL * [size];
		for (int i = 0; i < size; i++) {
			maze[i] = new CELL[size];
		}

		maze[cordY][cordX - 1].isPlayer = true;
		maze[cordY][cordX - 1].isVisited = true;
		maze[size - 2][size - 1].isVisited = true;
		maze[size - 2][size - 1].isPlayer = false;
		playerCord.playerY = 1;
		playerCord.playerX = 0;

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
				cout << "Want to play again? Y/N";
				
				switch (_getch()) {
				case 'Y':
				case 'y':
					system("cls");
					playerWon = false;
					break;
				case 'N':
				case 'n':
					exit(0);
					break;
				}
			}
			else {
				printMaze(maze, size, free, playerSym);

				cout << "\n";
				cout << "*--------------------------*" << endl;
				cout << "|                          |" << endl;
				cout << "|       Instructions:      |" << endl;
				cout << "|    Use the arrows or     |" << endl;
				cout << "|         W,A,S,D          |" << endl;
				cout << "|                          |" << endl;
				cout << "*--------------------------*" << endl;
				playerMovement(maze);
				system("cls");
			}
		}
	}
}