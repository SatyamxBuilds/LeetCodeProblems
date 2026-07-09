#pragma GCC optimize("O3")
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);
    int quotient = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    while (absDividend >= absDivisor) {
        long long tempDivisor = absDivisor;
        long long multiple = 1;
        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            multiple <<= 1;
        }
        absDividend -= tempDivisor;
        quotient += multiple;
    }
    return sign * quotient;
}