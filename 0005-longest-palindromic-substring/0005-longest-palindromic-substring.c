char* longestPalindrome(char* s)
{
    int n = strlen(s);

    if(n < 2)
        return s;

    int start = 0;
    int maxLen = 1;

    for(int i = 0; i < n;)
    {
        if(n - i <= maxLen / 2)
            break;

        int left = i;
        int right = i;

        while(right < n - 1 && s[right] == s[right + 1])
            right++;

        i = right + 1;

        while(left > 0 && right < n - 1 &&
              s[left - 1] == s[right + 1])
        {
            left--;
            right++;
        }

        int len = right - left + 1;

        if(len > maxLen)
        {
            maxLen = len;
            start = left;
        }
    }

    s[start + maxLen] = '\0';
    return s + start;
}