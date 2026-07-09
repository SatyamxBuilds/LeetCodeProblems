int longestValidParentheses(char* s) {
    int n = 0;
    while (s[n] != '\0') n++;  
    int maxLen = 0;
    int open = 0, close = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') open++;
        else close++;
        if (open == close) {
            int len = 2 * close;
            if (len > maxLen) maxLen = len;
        } else if (close > open) {
            open = 0;
            close = 0;
        }
    }
    open = 0;
    close = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') open++;
        else close++;
        if (open == close) {
            int len = 2 * open;
            if (len > maxLen) maxLen = len;
        } else if (open > close) {
            open = 0;
            close = 0;
        }
    }
    return maxLen;
}