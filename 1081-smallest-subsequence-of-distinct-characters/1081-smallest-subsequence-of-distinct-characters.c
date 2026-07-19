#pragma GCC optimize("O3")

char* smallestSubsequence(char* s) {
    int count[26] = {0};
    int visited = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    static char stack[27];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int curr = s[i] - 'a';
        count[curr]--;

        if ((visited & (1 << curr))) {
            continue;
        }

        while (top >= 0 && stack[top] > s[i] && count[stack[top] - 'a'] > 0) {
            visited &= ~(1 << (stack[top] - 'a'));
            top--;
        }

        stack[++top] = s[i];
        visited |= (1 << curr);
    }

    stack[top + 1] = '\0';
    return stack;
}