#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s)
{
    int n = strlen(s);

    char *stack = (char *)malloc(n);

    int top = -1;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (c == '(')
            stack[++top] = ')';
        else if (c == '{')
            stack[++top] = '}';
        else if (c == '[')
            stack[++top] = ']';
        else
        {
            if (top < 0 || stack[top] != c)
            {
                free(stack);
                return false;
            }
            top--;
        }
    }

    free(stack);
    return top == -1;
}