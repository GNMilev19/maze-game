#include <iostream>
#include <time.h>
using namespace std;

struct CELL {
    int X{};
    int Y{};
    bool isVisited = false;
    bool isWall = false;
};

void printMaze(CELL** maze, int size, char free) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j].isVisited == true) {
                cout << free << " ";
            }
            else {
                cout << "# ";
            }
        }
        cout << endl;
    }
}

/*void createWalls(CELL** maze, int size, int cellCount) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 2 == 0 || j % 2 == 0) {
                maze[i][j].isWall = true;
            }
            else {
                cellCount++;
            }
        }
    }
}*/

/*bool dirCheck(int dir, int size, int cordY, int cordX) {
    return ((dir == 0 && cordY == 1) ||
        (dir == 1 && cordX == size - 2) ||
        (dir == 2 && cordY == size - 2) ||
        (dir == 3 && cordX == 1));
}*/

int main()
{
    srand((unsigned int)time(NULL));
    int size;
    cin >> size;
    int cordY = 1, cordX = 1;
    char free = ' ';

    int cellCount = 0;

    CELL** maze = new CELL * [size];
    for (int i = 0; i < size; i++) {
        maze[i] = new CELL[size];
    }

    //createWalls(maze, size, cellCount);

    //int unvisitedCells = 0;
    //bool cellCheck = true;

    printMaze(maze, size, free);
}