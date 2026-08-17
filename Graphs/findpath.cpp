#include<iostream>
#include<list>
#include<queue>
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
    bool findPath(int source,int destination,vector<bool>&visited){
        if(source==destination){
            return true;
        }
        visited[source]=true;
        list<int>neig=l[source];
        for(int neighbor:neig){
            if(!visited[neighbor]){
                bool found=findPath(neighbor,destination,visited);
                if(found){
                    return true;
                }
            }
        }
        return false;
    }
};
    int main(){
        Graph graph(7);
        graph.addEdge(0,1);
        graph.addEdge(0,2);
        graph.addEdge(1,3);
        graph.addEdge(2,4);
        graph.addEdge(3,4);
        graph.addEdge(3,5);
        graph.addEdge(4,5);
        graph.addEdge(5,6);
        vector<bool>visited(graph.v,false);
        int source=0;
        int destination=6;
        bool pathExists=graph.findPath(source,destination,visited);
        if(pathExists){
            cout<<"Path exists between "<<source<<" and "<<destination<<endl;
        }else{
            cout<<"No path exists between "<<source<<" and "<<destination<<endl;
        }  
        return 0;
    } 