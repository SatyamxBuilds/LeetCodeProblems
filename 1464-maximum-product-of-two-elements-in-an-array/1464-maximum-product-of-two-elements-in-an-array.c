#pragma GCC optimize("O3")

int maxProduct(int* nums, int numsSize) {
    int max1 = 0;
    int max2 = 0;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val > max1) {
            max2 = max1;
            max1 = val;
        } else if (val > max2) {
            max2 = val;
        }
    }

    return (max1 - 1) * (max2 - 1);
}