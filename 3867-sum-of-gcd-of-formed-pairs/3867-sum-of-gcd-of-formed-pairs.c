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

static void quicksort(int* arr, int low, int high) {
    if (low >= high) return;
    int pivot = arr[low + (high - low) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quicksort(arr, low, j);
    quicksort(arr, i, high);
}

long long gcdSum(int* nums, int numsSize) {
    int currentMax = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > currentMax) {
            currentMax = nums[i];
        }
        nums[i] = quick_gcd(nums[i], currentMax);
    }

    quicksort(nums, 0, numsSize - 1);

    long long totalSum = 0;
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        totalSum += quick_gcd(nums[left], nums[right]);
        left++;
        right--;
    }

    return totalSum;
}