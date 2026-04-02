#include "graph.h"

int count_isolated(Graph* g) {
    int count = 0;

    for (int u = 0; u < MAX_NODES; u++) {
        int isolated = 1;

        for (int v = 0; v < MAX_NODES; v++) {
            if (g->adj[u][v] == 1) {
                isolated = 0;
                break;
            }
        }

        if (isolated) {
            count++;
        }
    }

    return count;
}














// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.
