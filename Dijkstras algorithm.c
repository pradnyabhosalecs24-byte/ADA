#include <stdio.h>
#define INF 999
int d[10], p[10], visited[10];
void dijkstra(int a[10][10], int s, int n)
{
    int u, v, i, j, min;
    for (v = 0; v < n; v++)
    {
        d[v] = INF;
        p[v] = -1;
        visited[v] = 0;
    }
    d[s] = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (v = 0; v < n; v++)
        {
            if (!visited[v] && a[u][v] && d[u] + a[u][v] < d[v])
            {
                d[v] = d[u] + a[u][v];
                p[v] = u;
            }
        }
    }
}
void path(int v, int s)
{
    if (p[v] != -1)
        path(p[v], s);
    if (v != s)
        printf("->%d", v);
}
void display(int s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i != s)
        {
            printf("%d", s);
            path(i, s);
            printf(" = %d\n", d[i]);
        }
    }
}
int main()
{
    int a[10][10], i, j, n, s;
    printf("Program for Single Source Shortest Path using Dijkstra Algorithm\n\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    dijkstra(a, s, n);
    printf("\nOUTPUT:\n");
    printf("Shortest paths from vertex %d:\n\n", s);
    display(s, n);
    return 0;
}
