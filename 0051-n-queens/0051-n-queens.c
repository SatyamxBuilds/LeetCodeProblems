#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void solve(int row, int n, int* queens, bool* cols, bool* diag1, bool* diag2, char*** results, int* returnSize) {
    if (row == n) {
        
        results[*returnSize] = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            results[*returnSize][i] = (char*)malloc((n + 1) * sizeof(char));
            memset(results[*returnSize][i], '.', n);
            results[*returnSize][i][queens[i]] = 'Q'; 
            results[*returnSize][i][n] = '\0';
        }
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!cols[col] && !diag1[row + col] && !diag2[row - col + n]) {
            
            queens[row] = col;
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n] = true;

            solve(row + 1, n, queens, cols, diag1, diag2, results, returnSize);

           
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n] = false;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {

    char*** results = (char***)malloc(500 * sizeof(char**));
    *returnSize = 0;

    int* queens = (int*)calloc(n, sizeof(int));
    bool* cols = (bool*)calloc(n, sizeof(bool));
    bool* diag1 = (bool*)calloc(2 * n, sizeof(bool));
    bool* diag2 = (bool*)calloc(2 * n, sizeof(bool));

    solve(0, n, queens, cols, diag1, diag2, results, returnSize);

    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

  
    free(queens);
    free(cols);
    free(diag1);
    free(diag2);

    return results;
}