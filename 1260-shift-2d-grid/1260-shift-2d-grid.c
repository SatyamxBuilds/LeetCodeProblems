#pragma GCC optimize("O3")

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;

    *returnSize = m;
    int* colSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) colSizes[i] = n;
    *returnColumnSizes = colSizes;

    int** result = (int**)malloc(m * sizeof(int*));
    int* data = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < m; i++) {
        result[i] = data + i * n;
    }

    k %= total;
    if (k < 0) k += total;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            int newFlatIndex = (r * n + c + k);
            if (newFlatIndex >= total) newFlatIndex -= total;
            
            data[newFlatIndex] = grid[r][c];
        }
    }

    return result;
}