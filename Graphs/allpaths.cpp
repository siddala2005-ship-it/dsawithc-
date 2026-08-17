#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<string>
using namespace std;
class Graph{
    public:
    int v;
    list<int>*l;
    Graph(int v){
        this->v=v;
        l=new list<int>[v];

    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfsHelper(int src,int dst,vector<bool>&vis,string path){
        if(src==dst){
            cout<<path<<src<<endl;
            return;
        }
        vis[src]=true;
        list<int>neig=l[src];
        path+=to_string(src)+" ";
        for(int neighbor:neig){
            if(!vis[neighbor]){
                dfsHelper(neighbor,dst,vis,path);
            }
        }
        // no need to trim `path` because it is passed by value (copy) to recursive calls
        vis[src]=false;
    }
    void bfsHelper(int src,int dst){
        if(src==dst){
            cout<<src<<endl;
            return;
        }
        vector<bool> vis(v,false);
        queue<pair<int,string>>q;
        q.push({src,""});
        vis[src]=true;
        while(!q.empty()){
            auto p=q.front(); q.pop();
            int current=p.first;
            string currentPath=p.second;
            for(int neighbor: l[current]){
                if(!vis[neighbor]){
                    string newPath = currentPath + to_string(current) + " ";
                    if(neighbor==dst){
                        cout<< newPath << neighbor << endl;
                        // do not return; continue to find other shortest paths
                    } else {
                        vis[neighbor]=true;
                        q.push({neighbor,newPath});
                    }
                }
            }
        }
    }

    void allPaths(int src,int dst){
        vector<bool>vis(v,false);
        string path="";
        dfsHelper(src,dst,vis,path);
    }
};
int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    int src=0;
    int dst=6;
    cout<<"All paths from "<<src<<" to "<<dst<<endl;
    g.allPaths(src,dst);
    cout<<"BFS discovered paths from "<<src<<" to "<<dst<<":\n";
    g.bfsHelper(src,dst);

}