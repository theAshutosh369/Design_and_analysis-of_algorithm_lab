
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *e;
};


void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->e[j].src;
            int v = graph->e[j].dest;
            int weight = graph->e[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = graph->e[i].src;
        int v = graph->e[i].dest;
        int weight = graph->e[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative weight cycle");
            return; 
        }
    }


    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    

}

int main()
{

    struct Graph* graph = new Graph;

    int V , E;

    cout << "No. of vertices : ";
    cin >> V;

    cout << "No. of Edges    : ";
    cin >> E;

    cout<<endl;


    graph->V = V;
    graph->E = E;
    graph->e = new Edge[E];

    for( int i = 0 ; i<E ;i++)
    {
        int s , d, w ;
        cout<<"Edge No. "<< i+1 <<endl;
        cout<<"Source      : ";
        cin>>s ;

        cout<<"Destination : ";
        cin>>d;

        cout<<"weight      : ";
        cin>>w;
        cout<<endl;

        graph->e[i].src = s ;
        graph->e[i].dest = d;
        graph->e[i].weight = w;
    }

    cout<<" Enter the source : ";
    int source;
    cin>>source;

    BellmanFord( graph,  source );

    return 0;
}
