#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Edge{
    public:
    int v;
    int wt;
    
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};
void bellmanFord(int src,vector<vector<Edge>>&graph,int v){
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<v;j++){
            for(Edge e:graph[j]){
                int u=j;
                int v=e.v;
                int wt=e.wt;
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
}
int main(){
    int v=6;
    vector<vector<Edge>>graph(v);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));

    bellmanFord(0,graph,v);
    return 0;
}