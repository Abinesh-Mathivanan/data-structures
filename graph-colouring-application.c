#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Define the graph structure
struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize the graph
void initializeGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices
void addEdge(struct Graph* graph, int vertex1, int vertex2) {
    graph->adjacencyMatrix[vertex1][vertex2] = 1;
    graph->adjacencyMatrix[vertex2][vertex1] = 1;
}

// Function to print the coloring of vertices
void printColoring(int colors[], int numVertices) {
    printf("Vertex Colors:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

// Function to check if it's safe to color a vertex with a specific color
int isSafe(struct Graph* graph, int vertex, int color, int colors[]) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && colors[i] == color) {
            return 0; // Not safe to color with this color
        }
    }
    return 1; // Safe to color with this color
}

// Function to perform graph coloring
void graphColoring(struct Graph* graph, int numColors) {
    int colors[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = 0; // Initialize all vertices with color 0 (not colored)
    }
    for (int vertex = 0; vertex < graph->numVertices; vertex++) {
        for (int color = 1; color <= numColors; color++) {
            if (isSafe(graph, vertex, color, colors)) {
                colors[vertex] = color;
                break;
            }
        }
    }
    printColoring(colors, graph->numVertices);
}

int main() {
    struct Graph graph;
    int numVertices, numEdges, numColors;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initializeGraph(&graph, numVertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        printf("Enter edge %d (vertex1 vertex2): ", i + 1);
        scanf("%d %d", &vertex1, &vertex2);
        addEdge(&graph, vertex1, vertex2);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);
    
    graphColoring(&graph, numColors);
    return 0;
}
