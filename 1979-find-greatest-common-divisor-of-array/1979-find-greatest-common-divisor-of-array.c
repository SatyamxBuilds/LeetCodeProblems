#pragma GCC optimize("O3")

static inline int quick_gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    int shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            int t = a; a = b; b = t;
        }
        b -= a;
    } while (b != 0);
    return a << shift;
}

int findGCD(int* nums, int numsSize) {
    int minVal = nums[0];
    int maxVal = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        } else if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    return quick_gcd(minVal, maxVal);
}