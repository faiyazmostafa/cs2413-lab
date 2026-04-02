#include "graph.h"

int has_triangle(Graph* g) {
    for (int u = 0; u < MAX_NODES; u++) {
        for (int v = u + 1; v < MAX_NODES; v++) {
            for (int w = v + 1; w < MAX_NODES; w++) {
                if (g->adj[u][v] == 1 &&
                    g->adj[v][w] == 1 &&
                    g->adj[u][w] == 1) {
                    return 1;
                }
            }
        }
    }

    return 0;
}