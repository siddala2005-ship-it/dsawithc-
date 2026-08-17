#include <iostream>
#include <list>
#include<vector>
using namespace std;

class Graph {
public:
    Graph(int v) {
        this->v = v;
        l = new list<pair<int, int>>[v];
    }

    ~Graph() {
        delete[] l;
    }

    void addEdge(int u, int v, int weight) {
        l[u].push_back({v, weight});
        l[v].push_back({u, weight});
    }

    void print() const {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (auto x : l[i]) {
                cout << "(" << x.first << ", " << x.second << ") ";
            }
            cout << "\n";
        }
    }

private:
    int v;
    list<pair<int, int>>* l;
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(1, 4, 2);
    graph.addEdge(2, 1, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 2);
    graph.addEdge(3, 1, 3);
    graph.addEdge(3, 2, 1);
    graph.addEdge(4, 2, 2);


    graph.print();
    return 0;
}
