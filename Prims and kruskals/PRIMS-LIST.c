#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define INF 100000

int main()
{   int v = 5;
    int G[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    int edge;

    int selected[v];

    memset(selected, false, sizeof(selected));

    edge = 0;

    selected[0] = true;

    int a=0;
    int y=0;

    printf("Edge : Weight\n");

    while (edge < v - 1)
    {
      int min = INF;
    for (int i = 0; i < v; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < v; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            a = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", a, y, G[a][y]);
        selected[y] = true;
        edge++;
    }

    return 0;
}