#include<iostream>
#include<list>
#include<queue>
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
void bfs(){
    queue<int>q;
    vector<bool>visited(v,false);
    q.push(0);
    visited[0]=true;

    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        list<int>neig=l[current];

        for(int neighbor:neig){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
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
    graph.bfs();
    return 0;
}