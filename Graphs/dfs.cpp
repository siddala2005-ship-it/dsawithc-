#include<iostream>
#include<list>
#include<stack>
#include<vector>
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
    void dfs(int source){
        stack<int>st;
        vector<bool>visited(v,false);
        st.push(source);
        visited[source]=true;

        while(!st.empty()){
            int current=st.top();
            st.pop();
            cout<<current<<" ";
            list<int>neig=l[current];

            for(int neighbor:neig){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    st.push(neighbor);
                }
            }
        }

    }
    void dfsRecursive(int source,vector<bool>&visited){
        visited[source]=true;
        cout<<source<<" ";
        list<int>neig=l[source];
        for(int neighbor:neig){
            if(!visited[neighbor]){
                dfsRecursive(neighbor,visited);
            }
        }
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

    graph.print();
    cout<<"DFS Traversal (Iterative): ";
    graph.dfs(0);
    cout<<endl;
    
    vector<bool>visited(graph.v,false);
    cout<<"DFS Traversal (Recursive): ";
    graph.dfsRecursive(0,visited);
    cout<<endl;

    return 0;
}