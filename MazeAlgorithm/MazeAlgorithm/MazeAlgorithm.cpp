#include <iostream>
#include <conio.h>
#include "MazeAlgorithm.h"
using namespace std;

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
                cout << "# ";
            }
        }
        cout << endl;
    }
}

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
            maze[*cordY - 1][*cordX].isVisited = true;
            ++* unvisitedCells;
        }
        *cordY -= 2;
        break;
    case 1:
        if (maze[*cordY][*cordX + 2].isVisited == false) {
            maze[*cordY][*cordX + 2].isVisited = true;
            maze[*cordY][*cordX + 1].isVisited = true;
            ++* unvisitedCells++;
        }
        *cordX += 2;
        break;
    case 2:
        if (maze[*cordY + 2][*cordX].isVisited == false) {
            maze[*cordY + 2][*cordX].isVisited = true;
            maze[*cordY + 1][*cordX].isVisited = true;
            ++* unvisitedCells++;
        }
        *cordY += 2;
        break;
    case 3:
        if (maze[*cordY][*cordX - 2].isVisited == false) {
            maze[*cordY][*cordX - 2].isVisited = true;
            maze[*cordY][*cordX - 1].isVisited = true;
            ++* unvisitedCells++;
        }
        *cordX -= 2;
        break;
    }
}



bool freeCheck(int dir, int size, int cordY, int cordX) {
    return (dir == 0 && cordY == 1) or
        (dir == 2 && cordY == size - 2) or
        (dir == 1 && cordX == size - 2) or
        (dir == 3 && cordX == 1);
}

int main() {
    srand((unsigned int)time(NULL));
    int cordY, cordX = 1;
    int cellCount = 0;
    char free = ' ';
    char player = '@';

    int size;
    cin >> size;

    cordY = 1;

    size = size * 2 + 1;

    CELL** maze = new CELL * [size];
    for (int i = 0; i < size; i++) {
        maze[i] = new CELL[size];
    }

    maze[cordY][cordX - 1].isPlayer = true;
    maze[size - 2][size - 1].isVisited = true;

    createWalls(maze, size, &cellCount);

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
    printMaze(maze, size, free, player);
}