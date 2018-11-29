#include "maze.h"

void solveMaze(ifstream &fin)
{
    maze Maze(fin);
    graph Graph((Maze.rows-1)*(Maze.cols-1));

}