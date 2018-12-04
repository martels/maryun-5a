#if (1)

#include "maze.h"

using namespace std;

void dfs(graph &g, NodeType v, NodeType dest)
{
  g.visit(v);
  int count = 0;

  if (v == dest)
  {
    cout << "found a path" << endl;
    return;
  }


  NodeType i = 0;
  while (i <= g.numNodes() || count < 3)
  {
    if (g.isEdge(v, i))
    {
      if (!g.isVisited(i))
      {
        count++;
        dfs(g, i, dest);
      }
    }
    i++;
  }
}

void solveMaze(maze &m, graph &g)
{
    m.mapMazeToGraph(g);
    int index = 0;
    int dest = m.getMap(m.rows-1, m.cols-1);
    g.clearVisit();
    dfs(g, index, dest);

}

#endif