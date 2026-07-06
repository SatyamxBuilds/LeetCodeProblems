int reverse(int x)
{
    int rev = 0;

    while (x)
    {
        int d = x % 10;
        x /= 10;

        if (rev > 214748364 || (rev == 214748364 && d > 7))
            return 0;
        if (rev < -214748364 || (rev == -214748364 && d < -8))
            return 0;

        rev = rev * 10 + d;
    }

    return rev;
}