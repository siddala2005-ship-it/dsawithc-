#include <iostream>
#include <map>
#include <vector>
#include<list>
#include<stack>

using namespace std;
class Graph{
    int v;
    list<int>*l;
    public:
    Graph(int v){
    this->v=v;
    l=new list<int>[v];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }
    void topoHelp(int src,vector<bool>&vis,stack<int>&s){
        vis[src]=true;
        list<int>neigh=l[src];
        for(int x:neigh){
            if(!vis[x]){
                topoHelp(x,vis,s);
            }
        }
        s.push(src);
    }
    void topo(){
        vector<bool>vis(v,false);
        stack<int>s;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                topoHelp(i,vis,s);
            }
        }
        while(!s.empty()){
            cout<<s.top();
            cout<<endl;
            s.pop();
        }

    }

};

int main() {
    Graph graph(6);
    graph.addEdge(5,0);
    graph.addEdge(4,0);
    graph.addEdge(4,7);
    graph.addEdge(3,7);
    graph.addEdge(2,3);
    graph.addEdge(5,2);
    graph.topo();



    
    return 0;
}
