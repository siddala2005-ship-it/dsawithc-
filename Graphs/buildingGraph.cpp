#include <iostream>
#include <list>
using namespace std;

class Graph {
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    ~Graph() {
        delete[] l;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() const {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (auto x : l[i]) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }

private:
    int v;
    list<int>* l;
};

int main() {
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.print();
    return 0;
}
