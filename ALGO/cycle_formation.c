#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph data structure
typedef struct {
    int vertices[MAX_VERTICES];
    int edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

// Utility function to initialize the graph
void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = 0;
        
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->edges[i][j] = 0;
        }
    }
}

// Utility function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
    graph->numEdges++;
}

// Depth-First Search recursive helper function
bool DFS(Graph* graph, int vertex, bool visited[], bool recStack[]) {
    visited[vertex] = true;
    recStack[vertex] = true;
    
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->edges[vertex][i]) {
            if (!visited[i]) {
                if (DFS(graph, i, visited, recStack))
                    return true;
            } else if (recStack[i]) {
                return true;
            }
        }
    }
    
    recStack[vertex] = false;
    return false;
}

// Main function to check if there is a cycle in the graph
bool hasCycle(Graph* graph) {
    bool visited[MAX_VERTICES] = { false };
    bool recStack[MAX_VERTICES] = { false };
    
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (DFS(graph, i, visited, recStack))
                return true;
        }
    }
    
    return false;
}
// Example usage
int main() 
{
    Graph graph;
    int numVertices = 4;
    
    initializeGraph(&graph, numVertices);
    
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 0);
    
    if (hasCycle(&graph))
        printf("Graph contains a cycle.\n");
    else
        printf("Graph does not contain a cycle.\n");
    
    return 0;
}

// output
// graph contain a cycle