#if (1)
#include "maze.h"

void dfs(graph &g, NodeType v, NodeType dest)
{
    g.visit(v);
    int count = 0;

    if(v == dest) return;
    
    NodeType i = 0;
    while(i <= g.numNodes() || count < 3)
    {
        if(g.isEdge(v, i))
        {
            if(!g.isVisited(i))
            {
                count++;
                dfs(g, i, dest);
            }
        }
        i++;
    }

}

void solveMaze(ifstream &fin)
{
    maze Maze(fin);
    graph Graph((Maze.rows-1)*(Maze.cols-1));
    int index = 1;

    Maze.mapMazeToGraph(Graph);
    int destination = Maze.getMap(Maze.rows-1, Maze.cols-1);

    Graph.clearVisit();
    dfs(Graph, 1, destination);
    
}

#endif