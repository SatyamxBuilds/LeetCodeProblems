int strStr(char* haystack, char* needle) {
    int m = 0;
    while (haystack[m] != '\0') m++;
    int n = 0;
    while (needle[n] != '\0') n++;
    if (n == 0) return 0;
    if (m < n) return -1;
    for (int i = 0; i <= m - n; i++) {
        int j = 0;
        while (j < n && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}