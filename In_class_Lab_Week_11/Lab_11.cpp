#include <iostream>
#include <vector>
#include <climits>

#define V 6 // Number of vertices

using namespace std;

int findMinKey(const vector<int>& key, const vector<bool>& mstSet) {
    int minKey = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

void primMST(const vector<vector<int>>& graph, int startNode) {
    vector<int> parent(V); 
    vector<int> key(V, INT_MAX); 
    vector<bool> mstSet(V, false); 

    key[startNode] = 0;
    parent[startNode] = -1; 

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
 
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    primMST(graph, 1);

    return 0;
}
