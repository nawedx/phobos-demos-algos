//B316011 - NAWED IMROZE - Prim's Algorithm - DAA - LAB9
#include<bits/stdc++.h>
using namespace std;
class node{
	int u;
	int v;
	int w;
	bool vis;
public:
	node(int U, int V, int W){
		u = U;
		v = V;
		w = W;
		vis = false;
	}
	int getu() const { return u; }
	int getv() const { return v; }
	int getw() const { return w; }
	bool getvis() { return vis; }
	void setvis() { vis = true; }
};

class compare{
public:
	int operator() (const node& n1, const node& n2){
		return n1.getw() > n2.getw();
	}
};

priority_queue <node, vector<node>, compare > pq;
int edges=0, nodes=0;


void addEdge(vector <pair<int, int> > adj[], int u, int v, int w){
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
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

int prim(vector <pair<int, int> > adj[]){
	int i, j, v, w, lowest = 0;
	vector<bool> vis(10, false);
	while(pq.empty() == false){
		node j = pq.top();
		j.setvis();
		pq.pop();
		int u = j.getu();
		vis[u] = true;
		int v = j.getv();
		//cout<<u<<" "<<v<<endl;
		int req = 100000, flag=0;
		for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            if(w < req && vis[v]==false){
            	cout<<u<<" "<<v<<" "<<w<<endl;
            	req = w;
            	flag = 1;
            }
        }
        cout<<"Lower weight : "<<req<<endl;
        if(flag==1)
        	lowest += req;
        /*
		for(i=0; i<adj[j].size(); i++){
			//cout<<adj[j][i]<<" ";
		}
		*/
		cout<<"Lowest"<<lowest<<endl;
	}
	return lowest;
}
int main(int argc, char **argv){
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
	in.close();
	in.open(argv[1]);
	vector<pair<int, int> > adj[nodes];
	while(!in.eof()){
		int x, y, w;
		in>>x>>y>>w;
		addEdge(adj, x, y, w);
		pq.push(node(x, y, w));
	}
	/*
	while (pq.empty() == false)
    {
        node p = pq.top();
        cout << "(" << p.getu() << ", " << p.getv() << ", " << p.getw() << ")";
        cout << endl;
        pq.pop();
    }
    */
	//printGraph(adj, nodes);
	int lowest = prim(adj);
	ofstream out;
	out.open("out.txt");
	cout<<lowest<<endl;
	out.close();
	return 0;
}
