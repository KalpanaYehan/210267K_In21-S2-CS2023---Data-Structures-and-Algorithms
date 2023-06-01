#include <iostream>
#include <vector>
#include <climits>
#define INF  999

using namespace std;

// function to find the nearest vertex 
int getNearest(vector<int>& distance, vector<bool>& shortestPathTree, int V) {
    int minDist = INF, minIndex;
    for (int v = 0; v < V; v++) {
        if (!shortestPathTree[v] && distance[v] <= minDist) {
            minDist = distance[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// display the output
void display(vector<int>& distance, int V, int source) {
    cout << "Source city = " << source << endl;
    for (int i = 0; i < V; i++) {
        cout << "Distance to city" << i << "\t" << distance[i]<<endl;
        cout << endl;
    }
}

// Dijkstra's algorithm
void dijkstra(vector<vector<int>>& graph, int source) {
    
    int V = graph.size();
    vector<int> dis(V, INF); 
    vector<bool> shortestPath(V, false);
    dis[source] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = getNearest(dis, shortestPath, V);
        shortestPath[u] = true;

        for (int v = 0; v < V; v++) {
            if (!shortestPath[v] && graph[u][v] != -1 &&
                dis[u] != INF && dis[u] + graph[u][v] < dis[v]) {
                dis[v] = dis[u] + graph[u][v];
                }
        }
    }
    display(dis, V, source);

}
int main() {
    
    vector<vector<int>> graph = {
        {-1, 10, -1, -1, 15, 5},
        {10, -1, 10, 30, -1, -1},
        {-1, 10, -1, 12, 5, -1},
        {-1, 30, 12, -1, -1, 20},
        {15, -1, 5, -1, -1, -1},
        {5, -1, -1, 20, -1, -1}
    };

    //int Vertices = graph.size();
    dijkstra(graph,0);
    return 0;
}
