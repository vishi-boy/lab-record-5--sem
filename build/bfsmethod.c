#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void bfs(int graph[MAX][MAX], int n, int startVertex) {
    int visited[MAX] = {0};
    Queue q;
    q.front = q.rear = -1;

    printf("BFS Traversal starting from vertex %d: ", startVertex);
    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, startVertex;
    int graph[MAX][MAX];

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

    bfs(graph, n, startVertex);

    return 0;
}
