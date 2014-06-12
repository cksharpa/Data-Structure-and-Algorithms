#include<iostream>
#include<list>

using namespace std;

class graph
{
    int V;
    list<int> *adj;
public:
    graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~graph()
    {
        delete [] adj;
    }
    void addEdge(int v, int w);
    void graphcoloring();
};

void graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void graph::graphcoloring()
{
    int result[V],u, cr;

    result[0] = 0;

    for(u =1; u<V;u++)
        result[u] = -1;

    bool available[V];
    for(cr =0;cr<V;cr++)
        available[cr] = false;

    for(u = 1;u< V;u++)
    {
        list<int>::iterator i;
        for(i=adj[u].begin();i != adj[u].end();++i)
            if(result[*i] != -1)
                available[result[*i]] =true;
        for(cr=0;cr<V;cr++)
            if(available[cr]==false)
                break;
        result[u] = cr;

        for(i = adj[u].begin();i!=adj[u].end();++i)
            if(result[*i] != -1)
                available[result[*i]]=false;

    }
    for(int u = 0;u<V;u++)
        cout<<"vertex "<<u<<" ---> Color "<<result[u]<<endl;
}

int main()
{
    graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    cout<<"coloring of graph \n";
    g1.graphcoloring();

    return 0;
}
