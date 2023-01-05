#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 5
int parent[V];

int find(int i) {
  while (parent[i] != i) i = parent[i];
  return i;
}

void union1(int i, int j) {
  int a = find(i);
  int b = find(j);
  parent[a] = b;
}

void kruskalMST(int cost[][V]) {
  int mincost = 0;

  for (int i = 0; i < V; i++) parent[i] = i;

  int edge_count = 0;
  while (edge_count < V - 1) {
    int min = INT_MAX, a = -1, b = -1;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (find(i) != find(j) && cost[i][j] < min) {
          min = cost[i][j];
          a = i;
          b = j;
        }
      }
    }

    union1(a, b);
    printf("Edge %d:(%d, %d) cost:%d \n", edge_count++, a, b, min);
    mincost += min;
  }
  printf("\n Minimum cost= %d \n", mincost);
}

int main() {
  int val, i, j, c = 0;
  int graph[V][V];
  printf("----------kruskals Algorithm----------\n");
  printf("1: Graph as adjacency matrix\n");
  printf("2: Graph as adjacency list\n");
  printf("Enter choice : ");
  scanf("%d", &val);
  switch (val) {
    case 1:
      for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
          scanf("%d", &graph[i][j]);
          if (graph[i][j] != 0) {
            c++;
          } else {
            graph[i][j] = INT_MAX;
          }
        }
      }
      break;
    case 2:
      printf("Enter in {node weight} format else -1 to terminate\n");
      for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
          graph[i][j] = INT_MAX;
        }
      }
      for (i = 0; i < V; i++) {
        int x;
        for (j = 0; j < V; j++) {
          scanf("%d", &x);
          if (x == -1) {
            break;
          }
          c++;
          scanf("%d", &graph[i][x]);
        }
      }
      break;
    default:
      printf("Oops wrong choice\n");
      return 0;
      break;
  }

  kruskalMST(graph);

  return 0;
}