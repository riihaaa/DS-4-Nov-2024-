/*Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using BFS method
c. Print all the nodes reachable from a given starting node in a digraph using DFS method*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int** adj;
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    g->adj = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->adj[i] = (int*)calloc(vertices, sizeof(int)); // Initialize to 0
    }
    return g;
}

void addEdge(Graph* g, int start, int end) {
    g->adj[start][end] = 1; // Directed edge from start to end
}

void printGraph(Graph* g) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

void bfs(Graph* g, int start) {
    int* visited = (int*)calloc(g->numVertices, sizeof(int));
    int* queue = (int*)malloc(g->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS starting from vertex %d: ", start);
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

void dfsUtil(Graph* g, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[v][i] && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

void dfs(Graph* g, int start) {
    int* visited = (int*)calloc(g->numVertices, sizeof(int));
    printf("DFS starting from vertex %d: ", start);
    dfsUtil(g, start, visited);
    printf("\n");
    free(visited);
}

void freeGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

int main() {
    Graph* g;
    int vertices, edges, start, end, choice;

    printf("Enter the number of vertices (cities): ");
    scanf("%d", &vertices);
    g = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        if (start >= 0 && start < vertices && end >= 0 && end < vertices) {
            addEdge(g, start, end);
        } else {
            printf("Invalid vertices! Please enter values between 0 and %d.\n", vertices - 1);
            i--; // Retry this edge input
        }
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Print the graph\n");
        printf("2. BFS from a starting node\n");
        printf("3. DFS from a starting node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printGraph(g);
                break;
            case 2:
                printf("Enter starting node for BFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    bfs(g, start);
                } else {
                    printf("Invalid starting node!\n");
                }
                break;
            case 3:
                printf("Enter starting node for DFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    dfs(g, start);
                } else {
                    printf("Invalid starting node!\n");
                }
                break;
            case 4:
                freeGraph(g);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}