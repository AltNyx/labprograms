//Bfs and Dfs
#include<stdio.h>
int n, g[20][20], visited[20];

void dfs(int c)
{
    int i;
    printf("\t%d", c);
    visited[c] = 1;
    for(i = 0; i < n; i++)
    {
        if(!visited[i] && (g[c][i] == 1))
            dfs(i);
    }
}

int main()
{
    int i, j , c;
    printf("\nEnter number of cities:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the starting city:");
    scanf("%d", &c);
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nThe cities reachable from starting city are:");
    dfs(c);
    return 0;
}
