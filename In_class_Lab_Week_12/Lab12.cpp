#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF std::numeric_limits<int>::max()

// Function to find the vertex with the minimum time
int minDistance(const vector<int>& dist, const vector<bool>& visited, int V) {
    int minDist = INF;
    int minIndex = -1;
    
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void dijkstra(const vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INF);  // Stores the minumum time from source to each vertex
    vector<bool> visited(V, false);  // Keeps track of visited vertices
    
    dist[src] = 0;  // Time taken from source to itself is 0
    
    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited, V);  
        visited[u] = true; 
        
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print the minumum time from the source vertex
    cout << "Minimum time from source vertex " << src << ":\n";
    for (int v = 0; v < V; ++v) {
        cout << "Vertex " << v << ": " << dist[v] << endl;
    }
}

int main() {
    int V = 6;  // Number of vertices in the graph

    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int src = 5;  // Source vertex
    
    dijkstra(graph, src, V);

    return 0;
}
