#include<stdio.h>

#define ALPHABET_SIZE 26

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    // Initialize cost matrix with high values (infinity)
    long long transCost[ALPHABET_SIZE][ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        for (int j = 0; j < ALPHABET_SIZE; ++j) {
            transCost[i][j] = (i == j) ? 0 : LLONG_MAX;
        }
    }

    // Fill cost matrix with given transformations
    for (int i = 0; i < costSize; ++i) {
        int from = original[i] - 'a';
        int to = changed[i] - 'a';
        transCost[from][to] = min(transCost[from][to], cost[i]);
    }

    // Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
    for (int k = 0; k < ALPHABET_SIZE; ++k) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                if (transCost[i][k] != LLONG_MAX && transCost[k][j] != LLONG_MAX) {
                    transCost[i][j] = min(transCost[i][j], transCost[i][k] + transCost[k][j]);
                }
            }
        }
    }

    // Calculate the minimum cost to transform source to target
    long long totalCost = 0;
    int n = strlen(source);
    for (int i = 0; i < n; ++i) {
        if (source[i] != target[i]) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (transCost[from][to] == LLONG_MAX) {
                return -1;
            }
            totalCost += transCost[from][to];
        }
    }

    return totalCost;
}

int main()
{


    return 0;
}