#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

int minKey(int key[], bool mstSet[]) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min) min = key[v], min_index = v;

  return min_index;
}

int printMST(int parent[], int graph[V][V]) {
  printf("Edge \tWeight\n");
  for (int i = 1; i < V; i++)
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
  int parent[V];

  int key[V];

  bool mstSet[V];

  for (int i = 0; i < V; i++) key[i] = INT_MAX, mstSet[i] = false;

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < V - 1; count++) {
    int u = minKey(key, mstSet);

    mstSet[u] = true;

    for (int v = 0; v < V; v++)
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        parent[v] = u, key[v] = graph[u][v];
  }

  printMST(parent, graph);
}

int main() {
  int val, i, j;
  int graph[V][V];
  printf("----------Prims Algorithm----------\n");
  printf("1: Graph as adjacency matrix\n");
  printf("2: Graph as adjacency list\n");
  printf("Enter choice : ");
  scanf("%d", &val);
  switch (val) {
    case 1:
      for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
          scanf("%d", &graph[i][j]);
        }
      }
      break;
    case 2:
      printf("Enter in {node weight} format else -1 to terminate\n");
      for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
          graph[i][j] = 0;
        }
      }
      for (i = 0; i < V; i++) {
        int x;
        for (j = 0; j < V; j++) {
          scanf("%d", &x);
          if (x == -1) {
            break;
          }
          scanf("%d", &graph[i][x]);
        }
      }
      break;
    default:
      printf("Oops wrong choice\n");
      return 0;
      break;
  }

  primMST(graph);

  return 0;
}