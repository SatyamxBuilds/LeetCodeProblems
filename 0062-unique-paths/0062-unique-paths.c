int uniquePaths(int m, int n) {
    int total_moves = m + n - 2;
    int k = (m - 1 < n - 1) ? m - 1 : n - 1;
    long long ans = 1;
    for (int i = 1; i <= k; i++) {
        ans = ans * (total_moves - k + i) / i;
    }
    return (int)ans;
}