#include<stdio.h>
#include<stdlib.h>

struct Adjlistnode
{
    int dest;
    struct Adjlistnode *next;
};

struct Adjlist
{
    struct Adjlistnode *head;
};

struct graph
{
    int v;
    struct Adjlist *array;
};

struct Adjlistnode* newAdjlistnode(int dest)
{
    struct Adjlistnode* newNode =
            (struct Adjlistnode*) malloc(sizeof(struct Adjlistnode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct graph* creategraph(int v)
{
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->v = v;
    graph->array = (struct Adjlist*)malloc(v*sizeof(struct Adjlist));
    int i;
    for(i=0; i< v; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addedge(struct graph *graph, int src, int dest)
{
    struct Adjlistnode *newNode = newAdjlistnode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjlistnode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printgraph(struct graph *graph)
{
    int v;
    for(v = 0; v<graph->v;++v)
    {
        struct Adjlistnode*pcrawl = graph->array[v].head;
        printf("adjacency list of vertex %d\n head ", v);
        while(pcrawl)
        {
            printf("-> %d", pcrawl->dest);
            pcrawl = pcrawl->next;
        }
        printf("\n");
    }
}


int main()
{
    int v=5;
    struct graph *graph = creategraph(v);
    addedge(graph, 0, 1);
    addedge(graph,0, 4);
    addedge(graph, 1,2);
    addedge(graph, 1,4);
    addedge(graph, 1,3);
    addedge(graph, 2, 3);
    addedge(graph, 3, 4);

    printgraph(graph);
    return 0;
}
