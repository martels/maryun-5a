#if (1)
#include "maze.h"
#include <stack>

void dfs(graph &g, int v)
{
    g.clearVisit();

    g.visit(v);
    
}

void solveMaze(ifstream &fin)
{
    maze Maze(fin);
    graph Graph((Maze.rows-1)*(Maze.cols-1));
    int index = 1;

    Maze.mapMazeToGraph(Graph);
    dfs(Graph, 1);
    
}

#endif