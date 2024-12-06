#include <stdio.h>
#define N 5
int visited[5];
//dfs
void dfs(int graph[][5], int start)
{
    if (visited[start] == 1)
    {
        return;
    }
    else{
        visited[start] = 1;
    }
    printf("%d ", start);
    for (int i = 0; i < N; i++)
    {
        if (graph[start][i] == 1 && visited[i] == 0)
        {
            dfs(graph, i); //recursive call
        }
    }
}

int main()
{
    
    int graph[N][N] = {
                     {0, 1, 1, 1, 0},
                     {1, 0, 1, 0 , 1},
                     {1, 1, 0, 1, 0},
                     {1, 0, 1, 0, 0},
                     {0, 1, 0, 0, 0}
                };

    dfs(graph, 0);
    return 0;
}