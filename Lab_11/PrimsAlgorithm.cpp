#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct Edge {
    int src, dest, weight;
};

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int>>>& graph, int src, int dest, int weight) {
    graph[src].push_back(make_pair(dest, weight));
    graph[dest].push_back(make_pair(src, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> primMST(vector<vector<pair<int, int>>>& graph, int V,int src) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    vector<Edge> mstEdges;

    
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        // Iterate through all adjacent vertices of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Construct the MST by using the parent array
    for (int i = 1; i < V; i++) {
        mstEdges.push_back({ parent[i], i, key[i] });
    }
    return mstEdges;
}

// Function to print the MST
void printMST(vector<Edge>& mstEdges) {
    cout << "Minimum Spanning Tree Edges:\n";
    for (const auto& edge : mstEdges) {
        cout << edge.src << " - " << edge.dest << " \tW =  " << edge.weight << endl;
    }
}

int main() {
    // Graph representation using adjacency list
    int V = 6; // Number of vertices
    int src = 0;//strating vertex
    vector<vector<pair<int, int>>> graph(V);

    // Adding edges to the graph
    addEdge(graph, 1, 0, 3);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 3, 2, 3);
    addEdge(graph, 4, 1, 10);
    addEdge(graph, 4, 3, 5);
    addEdge(graph, 5, 0, 1);
    addEdge(graph, 5, 2, 5);
    addEdge(graph, 5, 4, 4);

    
    vector<Edge> mstEdges = primMST(graph, V,src);
    printMST(mstEdges);
return 0;
}
