//prism algorithm
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;
    return min_index;
}
int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
}
void primMST(int graph[V][V])
{
    int parent[V],key[V]; 
    bool mstSet[V];  
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;   
    key[0] = 0;   
    parent[0] = -1;   
    for (int count = 0; count < V - 1; count++) 
    {   
        int u = minKey(key, mstSet);       
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}

//n_queen problem
#include<stdio.h>
#include<stdbool.h>
#define n 4
int i,j,row,col;
// print n-queen from board travel
void printnq(int board[n][n])
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(board[i][j])
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            } 
        }
    }
    printf("\n");
}
// safe check condition for row and column
bool safeqn(int board[n][n],int row,int col)
{
    for(i=0;i<col;i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    for(i=row,j=col;i<n && j>=0;i++,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}
//apply backtracking in board with column
bool recqn(int board[n][n],int col)
{
    if(col>=n)
    {
        return true;
    }
    for(i=0;i<n;i++)
    {
        if(safeqn(board,i,col))
        {
            board[i][col]=1;
            if(recqn(board,col+1))
            {
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}
//solve n-queen
bool solveqn()
{
    int board[n][n]= { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    if(recqn(board,0)==false)
    {
        printf("no solution found");
        return false;
    }
    else
    {
        printnq(board);
        return true;
    }
}
// call solve in main method
int main()
{
    solveqn();
    return 0;
}

//floyd-warshall algorithm
#include<stdio.h>
#define vertex 4
#define inf 999
void printmatrix(int matrix[][vertex])
{
    int i,j;
    for(i=0;i<vertex;i++)
    {
        for(j=0;j<vertex;j++)
        {
            if(matrix[i][j]==inf)
            {
                printf("%4s","inf");
            }
            else
            {
                printf("%4d",matrix[i][j]);
            }
        }
        printf("\n");
    }
}
void floyd(int graph[][vertex])
{
    int matrix[vertex][vertex];
    int i,j,k;
    for(i=0;i<vertex;i++)
    {
        for(j=0;j<vertex;j++)
        {
            matrix[i][j]=graph[i][j];
        }
    }
    for(k=0;k<vertex;k++)
    {
        for(i=0;i<vertex;i++)
        {
            for(j=0;j<vertex;j++)
            {
                if (matrix[i][k]+matrix[k][j]<matrix[i][j])
                {
                    matrix[i][j]= matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
    printmatrix(matrix);
}
int main()
{
    int graph[vertex][vertex]={{0,5,inf,10},{inf,0,3,inf},{inf,inf,0,1},{inf,inf,inf,0}};   // 0   5   8   9, inf   0   3   4, inf inf   0   1, inf inf inf   0
    //int graph[vertex][vertex]={{0,3,inf,5},{2,0,inf,4},{inf,1,0,inf},{inf,inf,2,0}};        // 0   3   7   5, 2   0   6   4, 3   1   0   5, 5   3   2   0
    floyd(graph);
}

// matrix multiplication
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10][10],b[10][10],m[10][10],r,c,i,j,k;
    printf("enter no of row:\n");
    scanf("%d",&r);
    printf("enter no of column:\n");
    scanf("%d",&c);
    printf("enter matrix 1 element");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter matrix 2 element");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("matrix1 X matrix2 =");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            m[i][j]=0;
            for(k=0;k<c;k++)
            {
                m[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}