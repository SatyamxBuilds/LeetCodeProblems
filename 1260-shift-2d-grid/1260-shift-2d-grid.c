#pragma GCC optimize("O3")

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;

    k = k % total;

    int** result = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    if (k == 0) {
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                result[r][c] = grid[r][c];
            }
        }
        return result;
    }

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            int oldFlatIndex = r * n + c;
            int newFlatIndex = (oldFlatIndex + k) % total;
            
            int newR = newFlatIndex / n;
            int newC = newFlatIndex % n;
            
            result[newR][newC] = grid[r][c];
        }
    }

    return result;
}