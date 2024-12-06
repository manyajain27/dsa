#include<stdio.h>

#define N 6
int queue[N]; 
int front = -1, rear = -1;

void enqueue(int data){
    if(rear == N-1){
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1){ 
        front = rear= 0;
        queue[rear] = data;
    }
    else{ 
        rear++;
        queue[rear] = data;
    }
    
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }
    else if(front == rear){ 
        front = rear = -1;
    }
    else{
        front++;
    }
}

int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}



void bfs(int graph[][N], int visited[], int start, int vertices){
    
    //initialize visited array to [0,0,0,0,0,0,0,0,0,0]
    for(int i = 0; i < vertices; i++){
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    while(!isEmpty()){
        int current = queue[front];
        printf("%d ", current);
        dequeue();

        for(int i = 0; i < vertices; i++){
            if(graph[current][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
        }

    }


}

int main(){
    
    int adj[N][N] = {
                     {0, 1, 1, 1, 0},
                     {1, 0, 1, 0 , 1},
                     {1, 1, 0, 1, 0},
                     {1, 0, 1, 0, 0},
                     {0, 1, 0, 0, 0}
                };

    int visited[N];
    bfs(adj, visited, 0, N);
    return 0;

}


    // int vertices, edges, start;
    // int visited[N];
    // printf("Enter the number of vertices: ");
    // scanf("%d", &vertices);
    // printf("Enter the number of edges: ");
    // scanf("%d", &edges);

    // int graph[N][N];
    // for(int i = 0; i < vertices; i++){
    //     for(int j = 0; j < vertices; j++){
    //         graph[i][j] = 0; //initialize the adjacency matrix to 0
    //     }

    // }
    // for(int i = 0; i < edges; i++){
    //     int u, v;
    //     printf("Enter the vertices of the edge: ");
    //     scanf("%d %d", &u, &v);
    //     graph[u][v] = 1;
    //     graph[v][u] = 1;
    // }

    // printf("Enter the starting vertex: ");
    // scanf("%d", &start);
    // bfs(graph, visited, start, vertices);

    // return 0;