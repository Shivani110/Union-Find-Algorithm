#include <bits/stdc++.h>
using namespace std;

class U_edge
{
public:
	int S, D;
};

class U_Graph
{
public:
	int vertexs, edges;
	U_edge*e;
};

U_Graph* NewGraph(int vertexs, int edges)
{
	U_Graph* U_graph = new U_Graph();
	U_graph->vertexs = vertexs;
	U_graph->edges = edges;

	U_graph->e = new U_edge[U_graph->edges * sizeof(U_edge)];

	return U_graph;
}

int U_findfn(int root[], int a)
{
	if (root[a] == -1)
		return a;
	return U_findfn(root, root[a]);
}

void Union_fn(int root[], int p, int q)
{
	root[p] = q;
}

int cycle(U_Graph* U_graph)
{
	int* root = new int[U_graph->vertexs * sizeof(int)];

	memset(root, -1, sizeof(int) * U_graph->vertexs);

	for (int a = 0; a < U_graph->edges; ++a) 
	{
		int p = U_findfn(root, U_graph->e[a].S);
		int q = U_findfn(root, U_graph->e[a].D);

		if (p == q)
			return 1;

		Union_fn(root, p, q);
	}
	return 0;
}
int main()
{
	int vertexs = 5, edges = 5;
	U_Graph* U_graph = NewGraph(vertexs, edges);
	U_graph->e[0].S = 0;
	U_graph->e[0].D = 1;

	U_graph->e[1].S = 1;
	U_graph->e[1].D = 3;

	U_graph->e[2].S = 2;
	U_graph->e[2].D = 4;
	
	U_graph->e[3].S = 4;
	U_graph->e[3].D = 5;
	
	U_graph->e[4].S = 5;
	U_graph->e[4].D = 2;

	if (cycle(U_graph))
		cout << "graph contains cycle";
	else
		cout << "graph doesn't contain cycle";

	return 0;
}


