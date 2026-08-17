#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int v;
    list<int>*l;
public:
    Graph(int v){
        this->v=v;
        l= new list<int>[v];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<":";
            list<int>neig=l[i];
            for(int x:neig){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    bool bipartiteGraph(){
        vector<bool>vis(v,false);
        vector<int>color(v,-1);
        queue<int>q;
        q.push(0);
        vis[0]=true;    
        while(!q.empty()){
            int current=q.front();
            q.pop();
            list<int>neig=l[current];
            for(int neighbor:neig){
                if(!vis[neighbor]){
                    vis[neighbor]=true;
                    color[neighbor]=1-color[current];
                    q.push(neighbor);
                }
                else{
                    if(color[neighbor]==color[current]){
                        cout<<"Not Bipartite Graph"<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }

};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.print();
    if(g.bipartiteGraph()){
        cout<<"Bipartite Graph"<<endl;
    }
    else{
        cout<<"Not Bipartite Graph"<<endl;
    }
    return 0;
}