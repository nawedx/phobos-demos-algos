//B316011 - NAWED IMROZE - Dijkstra Algorithm - DAA - LAB10
#include<bits/stdc++.h>
using namespace std;
int nodes = 0, edges = 0;;
void addEdge(vector <pair<int, int> > adj[], int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
}

void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}
class Graph
{
    int V;
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}
 
void Graph::dijkstra()
{
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
 
    int source = 0;
    vector<int> key(V, 100000);
    vector<int> parent(V, -1);
    vector<bool> s(V, false);
    pq.push(make_pair(0, source));
    key[source] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
 
        s[u] = true; 
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
             
            if (key[v] > key[u] + weight)
            {
                key[v] = key[u] + weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    int sum=0;
    for (int i = 0; i < V; ++i){
        //cout<<key[i]<<" ";
        sum += key[i];
    }
    ofstream out;
    out.open("out.txt");
    out<<sum<<endl;
    out.close();
}

int main(int argc, char **argv)
{
    ifstream in;
    in.open(argv[1]);
    int i=0, j=0;
    while(!in.eof()){
        int x, y, w;
        in>>x>>y>>w;
        //cout<<x<<" "<<y<<" "<<w<<endl;
        edges++;
        j=max(x, j);
        j=max(y, j);
    }
    nodes=j;
    int V = j+1;
    in.close();
    Graph g(V);
    in.open(argv[1]);
    vector<pair<int, int> > adj[nodes];
    while(!in.eof()){
        int x, y, w;
        in>>x>>y>>w;
        g.addEdge(x, y, w);      
    }
    //printGraph(adj, nodes);
    g.dijkstra();
    return 0;
}