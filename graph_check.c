#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define visited 2
#define finished 3

int n;    /*Number of vertices in the graph */
int adj[MAX][MAX];
void create_graph( );

int state[MAX];

void DF_Traversal();
void DFS(int v);

int main()
{
        create_graph();
        DF_Traversal();
        return 0;
}/*End of main()*/

void DF_Traversal()
{
        int v;

        for(v=0; v<n; v++)
                state[v] = initial;

        DFS(0);/*start DFS from vertex 0*/

        for(v=0; v<n; v++)
        {
                if(state[v]==initial)
                        DFS(v);
        }
        printf("\nGraph is Acyclic\n");
}/*End of DF_Traversal( )*/

void DFS(int v)
{
        int i;
        state[v] = visited;

        for(i=0; i<n; i++)
        {
                if(adj[v][i]==1)
                {
                        if(state[i]==initial)
                                DFS(i);
                        else if(state[i]==visited)
                        {
                                printf("\nBack edge  (%d,%d) found\n", v, i);
                                printf("\nGraph is cyclic\n");
                                exit(1);
                        }
                }
        }
        state[v] = finished;
}/*End of DFS()*/

void create_graph()
{
        int i,max_edges,origin,destin;

        printf("\nEnter number of vertices : ");
        scanf("%d",&n);
        max_edges = n*(n-1);

        for(i=1;i<=max_edges;i++)
        {
                printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
                scanf("%d %d",&origin,&destin);
                if( (origin == -1) && (destin == -1) )
                        break;
                if( origin >= n || destin >= n || origin<0 || destin<0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                {
                        adj[origin][destin] = 1;
                }
        }
}

// OUTPUT :
// C Program to find whether a Directed Graph is Cyclic or not 

// Enter number of vertices : 6

// Enter edge 1( -1 -1 to quit ) : 0 1

// Enter edge 2( -1 -1 to quit ) : 0 2

// Enter edge 3( -1 -1 to quit ) : 0 3

// Enter edge 4( -1 -1 to quit ) : 1 3

// Enter edge 5( -1 -1 to quit ) : 3 4

// Enter edge 6( -1 -1 to quit ) : 2 5

// Enter edge 7( -1 -1 to quit ) : 5 4

// Enter edge 8( -1 -1 to quit ) : -1 -1

// Graph is Acyclic