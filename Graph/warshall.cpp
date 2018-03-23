//B316011 - NAWED IMROZE - Floyd Warshall Algorithm - DAA - LAB10
#include<bits/stdc++.h>
using namespace std;
int nodes = 0, edges = 0;
int ar[10][10];
void initGraph(){
	int i, j;
	for(i=0; i<nodes; i++){
		for(j=0; j<nodes; j++)
			if(i==j)
				ar[i][j] = 0;
			else
				ar[i][j] = 10000;
	}
}

void printGraph(){
	int i, j;
	for(i=0; i<nodes; i++){
		for(j=0; j<nodes; j++)
			cout<<ar[i][j]<<" ";
		cout<<endl;
	}
}

void warshall(){
	int i, j, k;
	for(k=0; k<nodes; k++){
		for(i=0; i<nodes; i++){
			for(j=0; j<nodes; j++){
				if(ar[i][k]!=10000 && ar[k][j]!=10000)
					ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);
			}
		}
	}
	int sum = 0;
	for(i=0; i<nodes; i++){
		for(j=0; j<nodes; j++)
			if(ar[i][j]!=10000)
				sum+=ar[i][j];
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
    nodes = j+1;
    in.close();
    in.open(argv[1]);
    initGraph();
    while(!in.eof()){
        int x, y, w;
        in>>x>>y>>w;
        ar[x][y] = w;
    }
    //printGraph();
    warshall();
    return 0;
}