#include<iostream>
#include<list>

using namespace std;

class graph
{
	int V;
	list<int> *adj;
	void dfsutil(int v, bool visited[]);
public:
	graph(int V);
	void addedge(int v, int w);
	void dfs(int v);
};

graph::graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void graph:: addedge(int v, int w)
{
	adj[v].push_back(w);
}

void graph::dfsutil(int v, bool visited[])
{
	visited[v] = true;
	cout<< v<< " ";
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			dfsutil(*i, visited);
}

void graph::dfs(int v)
{
	bool *visited = new bool[V];
	for(int i = 0; i< V; i++)
		visited[i] = false;
	dfsutil(v, visited);
}

int main()
{
	graph g(4);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,2);
	g.addedge(2,0);
	g.addedge(2,3);
	g.addedge(3,3);

	cout<<"following is depth first traversal \n";
	g.dfs(2);
	return 0;
}
