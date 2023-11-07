#include <iostream>
#include <climits>

const int MAX_N = 16; // Maximum number of vertices

int n; // Number of vertices
int graph[MAX_N][MAX_N]; // Adjacency matrix for the graph
int best_path[MAX_N];
int current_path[MAX_N];
bool visited[MAX_N];
int best_weight = INT_MAX;
int current_weight = 0;

const int INF = 999; // "999" represents infinity

void tsp(int u, int depth) {
    visited[u] = true;
    current_path[depth] = u;

    if (depth == n - 1) {
        if (graph[u][0] != INF && current_weight + graph[u][0] < best_weight) {
            best_weight = current_weight + graph[u][0];
            for (int i = 0; i < n; i++) {
                best_path[i] = current_path[i];
            }
        }
    }

    for (int v = 0; v < n; v++) {
        if (!visited[v] && graph[u][v] != INF) {
            current_weight += graph[u][v];

            if (current_weight < best_weight) {
                tsp(v, depth + 1);
            }

            current_weight -= graph[u][v];
        }
    }

    visited[u] = false;
}

int main() {
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    std::cout << "Enter the source and destination vertices for each edge (Enter 999 for no edge):" << std::endl;
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            std::cout << "Enter the weight from vertex " << i << " to vertex " << j << ": ";
            std::cin >> graph[i][j];
            if (graph[i][j] == 999) {
                graph[i][j] = INF; // Convert 999 to infinity
            }
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    tsp(0, 0);

    std::cout << "Optimal TSP Path: ";
    for (int i = 0; i < n; i++) {
        std::cout << best_path[i] << " ";
    }
    std::cout << "0" << std::endl;

    std::cout << "Total Weight: " << best_weight << std::endl;

    return 0;
}

