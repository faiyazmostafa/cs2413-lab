#include "graph.h"

int count_edges(Graph* g) {
    int count = 0;

    for (int u = 0; u < MAX_NODES; u++) {
        for (int v = 0; v < MAX_NODES; v++) {
            if (g->adj[u][v] == 1) {
                count++;
            }
        }
    }

    return count / 2;
}