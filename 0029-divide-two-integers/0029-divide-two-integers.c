#pragma GCC optimize("O3")

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;

    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);
    long long quotient = 0;

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    for (int i = 31; i >= 0; i--) {
        if ((absDivisor << i) <= absDividend) {
            absDividend -= (absDivisor << i);
            quotient |= (1LL << i);
        }
    }

    return sign * quotient;
}