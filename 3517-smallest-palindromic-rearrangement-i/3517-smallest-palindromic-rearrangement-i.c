#pragma GCC optimize("O3")

char* smallestPalindrome(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;

    int freq[26] = {0};
    int halfLen = len / 2;

    for (int i = 0; i < halfLen; i++) {
        freq[s[i] - 'a']++;
    }

    int ptr = 0;
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            s[ptr++] = 'a' + i;
            freq[i]--;
        }
    }

    if (len % 2 != 0) {
        ptr++; 
        
    }

    for (int i = ptr; i < len; i++) {
        s[i] = s[len - 1 - i];
    }

    return s;
}