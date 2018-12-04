#if (1)
#include "maze.h"
#include <iostream>

using namespace std;



void solveMaze(ifstream &fin)
{
  maze Maze(fin);
  graph Graph((Maze.rows - 1) * (Maze.cols - 1));
  int index = 1;

  Maze.mapMazeToGraph(Graph);
  int destination = Maze.getMap(Maze.rows - 1, Maze.cols - 1);

  Graph.clearVisit();
  dfs(Graph, 1, destination);
}

#endif