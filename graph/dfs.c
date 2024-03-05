#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
int Graph[MAX_VERTICES][MAX_VERTICES];
 
void create_edge(int x , int y)
{
    Graph[x][y]=1;
    Graph[y][x]=1;
}

void loop_edge(int edge)
{   
    for(int i=0 ; i < edge ; i++)
    {
        int u, v;
        printf("Enter edge %d (u v): ", i +1 );
        scanf("%d %d", &u, &v);
        create_edge(u, v);
    }
}

void DFS(int edge, int vertices, int visited[]) {
    visited[edge] = 1; 
    printf("%d ", edge);

    for (int i = 1; i <= vertices; i++) {
        if (Graph[edge][i] == 1 && visited[i] == 0) {
            DFS(i, vertices, visited);
        }
    }
}

void DFS_Traversal(int vertices) {
    int visited[MAX_VERTICES] = {0}; 

    printf("DFS Traversal: ");
    for (int i = 1; i <= vertices; i++) {
        if (visited[i] == 0) {
            DFS(i, vertices, visited);
        }
    }
    printf("\n");
}

void print_graph(int vertices)
{
    printf("ADJECENT MATRIX:\n");
    for(int i=1; i<=vertices; i++)
    {
        for(int j=1 ; j<=vertices ; j++)
        {
            printf("%d ", Graph[i][j]);
        }printf("\n");
    }

}

int main()
{
    int vertices,edge;
    printf("plz enter the num of vertices you want:-\n");
    scanf("%d" , &vertices );
    printf("plz enter the num of edge you want:-\n");
    scanf("%d" , &edge);

    loop_edge(edge);
    print_graph(vertices);
    DFS_Traversal(vertices);
}