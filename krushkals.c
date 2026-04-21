#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Edge {
    int u, v, weight;
};
struct Edge edges[MAX], result[MAX];
int parent[MAX];
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootV] = rootU;
}
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
void kruskal(int V, int E) {
    int i, count = 0;
    qsort(edges, E, sizeof(edges[0]), compare);
    for (i = 0; i < V; i++)
        parent[i] = i;
    for (i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            result[count++] = edges[i];
            unionSet(u, v);
        }
    }

    printf("Edges in MST:\n");
    for (i = 0; i < count; i++) {
        printf("%d -- %d == %d\n",
               result[i].u, result[i].v, result[i].weight);
    }
}

int main() {
    int V, E, i;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u,
                          &edges[i].v,
                          &edges[i].weight);
    }

    kruskal(V, E);

    return 0;
}
