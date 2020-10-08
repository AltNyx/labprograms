//Bfs and Dfs
#include<stdio.h>
int n, g[20][20], visited[20], q[20], f = 0, r = -1;

void bfs(int c)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(!visited[i] && (g[c][i] == 1))
            q[++r] = i;
    }

    if(f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
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

    for(i = 0; i < n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("\nEnter the starting city:");
    scanf("%d", &c);
    bfs(c);
    printf("\nThe cities reachable from starting city are:");
    for(i = 0; i < n; i++)
    {
        if(visited[i])
        {
            printf("\t%d", i);
        }
    }
    return 0;
}
