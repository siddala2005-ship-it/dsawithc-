#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<utility>
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
    void dijkstras(int src,vector<vector<Edge>>&graph,int v){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(v,INT_MAX);
        pq.push({0,src});
        dist[src]=0;
        while(pq.size()>0){
            int u=pq.top().second;
            pq.pop();
            for(Edge e:graph[u]){
                int v=e.v;
                int wt=e.wt;
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
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


dijkstras(0,graph,v);

return 0;
}