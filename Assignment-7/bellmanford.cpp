#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source;
    int dest;
    int weight;
};

class Graph{
public:
    int v,e;
    Edge *edge;

    Graph(int v,int e){
        this->v=v;
        this->e=e;
        edge=new Edge[e];
    }

    void addEdge(int u,int v,int w,int c){
        edge[c].source=u;
        edge[c].dest=v;
        edge[c].weight=w;
    }

    void BellmanFord(int source){
             int distance[v];
             for(int i=0;i<v;i++){
				if(i==source){
					distance[i] = 0;
				}
				else
				{
					distance[i] = INT_MAX;
				}
			}
			
			for(int i=0;i<=v-1;i++){
				for(int j=0;j<e;j++){
					int src =edge[j].source;
					int dest = edge[j].dest;
					int wt = edge[j].weight;
					
				
					if(distance[src] !=INT_MAX && distance[src] + wt < distance[dest]){
						distance[dest] = distance[src] + wt;
					} 
				}
			}
			
			for(int j=0;j<e;j++){
			   int src =edge[j].source;
					int dest = edge[j].dest;
					int wt = edge[j].weight;
				
					
					if(distance[src] !=INT_MAX && distance[src] + wt < distance[dest]){
						cout<<"graph has negative cycle"; 
					    return;
					}
					
			}
            cout<<"Assigned Values to Vertices"<<endl;
			for(int i=0;i<v;i++){
				cout<<i<<" - "<<distance[i]<<endl;
			}
		return;
			
		}	
};
int main(){
    cout<<"Enter no of vetices and edges"<<endl;
     int v,e;
	cin>>v>>e;
	Graph g(v,e);
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.addEdge( u, v, w,i);
		 
	}
	g.BellmanFord(0);

    return 0;
}
/*
Enter no of vetices and edges
5 6
0 1 2
1 3 3
0 2 2
2 4 4
3 2 6
4 3 -5
Assigned Values to Vertices
0 - 0
1 - 2
2 - 2
3 - 1
4 - 6

*/

