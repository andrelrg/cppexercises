//Dijkstra's algorithm

#include<stdio.h>
#include<iostream>
#include <climits>

#define V 9

int minDist(int dist[V], bool verified[V]){
    int min = INT_MAX;
    int index = 0;

    for(int i =0; i<V; i++){
        if(!verified[i] && dist[i] <= min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int from, int to){
    int dist[V];
    bool verified[V];
    for (int i = 0; i<V; i++){
        dist[i] = INT_MAX;
        verified[i] = false;
    }
    
    dist[0] = 0;
    for (int a = 0; a<V; a++){
        int u = minDist(dist, verified);

        verified[u] = true;

        for(int b = 0; b<V; b++){
            if (graph[u][b] && !verified[b] && dist[u] != INT_MAX && 
                dist[u] + graph[u][b] < dist[b]){
                    dist[b] = dist[u] + graph[u][b];
                }
        }
        for (int i = 0; i<V; i++){
            printf("dist %d: %d | ver: %d\n", i, dist[i], verified[i]);
        }
    }

}

int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0, 2);
}