#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n; // Number of vertices

// Function to perform DFS
void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    if (startVertex >= n || startVertex < 0) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    dfs(startVertex);
    printf("\n");

    return 0;
}