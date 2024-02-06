// Floyd-Warshall Algorithm in C
#include <stdio.h>

// defining the number of vertices
#define nV 4

// define value of infinity
#define INF 999

// method to print matrix
void printMatrix(int matrix[][nV]) 
{
  for (int i = 0; i < nV; i++) 
  {
    for (int j = 0; j < nV; j++) 
    {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}
// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) 
{
  int matrix[nV][nV], i, j, k;

// convert graph to matrix
  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
    printMatrix(matrix);
  }
}

int main() 
{
  // taking input of graph value
  // int graph[nV][nV] = {{0, 3, INF, 5},{2, 0, INF, 4},{INF, 1, 0, INF},{INF, INF, 2, 0}};
  int graph[nV][nV]={{0,3,INF,7},{8,0,2,INF},{5,INF,0,1},{2,INF,INF,0}};
  floydWarshall(graph);
}