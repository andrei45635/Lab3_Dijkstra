#include <iostream>
#define inf 999

void Dijkstra(int G[6][6], int n, int varf_start) {
    int cost[6][6], distance[6], pred[6], visited[6];
    int mindistance, count, urm_vf, i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0) {
                cost[i][j] = inf;
            } else {
                cost[i][j] = G[i][j];
            }
        }
    }
    for (i = 0; i < n; i++) {
        distance[i] = cost[varf_start][i];
        pred[i] = varf_start;
        visited[i] = 0;
    }
    distance[varf_start] = 0;
    visited[varf_start] = 1;
    count = 1;
    while (count < n - 1) {
        mindistance = inf;
        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < mindistance) {
                mindistance = distance[i];
                urm_vf = i;
            }
        }
        visited[urm_vf] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && ((cost[urm_vf][i] + mindistance) < distance[i])) {
                distance[i] = cost[urm_vf][i] + mindistance;
                pred[i] = urm_vf;
            }
        }
        count++;
    }
    for (i = 0; i < n; i++) {
        if (i != varf_start) {
            std::cout << "\nDistanta de la nod " << i << " = " << distance[i];
            std::cout << "\nDrumul este: " << i;
            j = i;
            do {
                j = pred[j];
                std::cout << "<-" << j;
            } while (j != varf_start);
        }
    }
}

int main() {
    int G[6][6] = {{0,  1, 0, 3, 10},
                   {1,  0, 5, 0, 0},
                   {0,  5, 0, 2, 1},
                   {3,  0, 2, 0, 6},
                   {10, 0, 1, 6, 0}};
    int n = 5;
    int varf_start = 0;
    Dijkstra(G, n, varf_start);
    return 0;
}
