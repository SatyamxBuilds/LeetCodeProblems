#pragma GCC optimize("O3")

bool isMatch(const char* s, const char* p) {
    int sLen = 0;
    while (s[sLen] != '\0') sLen++;
    
    int pLen = 0;
    while (p[pLen] != '\0') pLen++;

    bool dp[1005] = {false};
    bool prev[1005] = {false};

    prev[0] = true;

    for (int j = 1; j <= pLen; j++) {
        if (p[j - 1] == '*') {
            prev[j] = prev[j - 2];
        }
    }

    for (int i = 1; i <= sLen; i++) {
        dp[0] = false; 

        for (int j = 1; j <= pLen; j++) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 2];

                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[j] = dp[j] || prev[j];
                }
            } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[j] = prev[j - 1];
            } else {
                dp[j] = false;
            }
        }

        for (int j = 0; j <= pLen; j++) {
            prev[j] = dp[j];
        }
    }

    return prev[pLen];
}