int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int capacity = numsSize * 2;
    if (capacity < 8) capacity = 8;
    int* keys = (int*)malloc(capacity * sizeof(int));
    int* indices = (int*)malloc(capacity * sizeof(int));
    for (int i = 0; i < capacity; i++) indices[i] = -1;
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        unsigned int h = (unsigned int)complement % capacity;
        while (indices[h] != -1) {
            if (keys[h] == complement) {
                result[0] = indices[h];
                result[1] = i;
                free(keys);
                free(indices);
                return result;
            }
            h = (h + 1) % capacity;
        }
        unsigned int hi = (unsigned int)nums[i] % capacity;
        while (indices[hi] != -1) {
            hi = (hi + 1) % capacity;
        }
        keys[hi] = nums[i];
        indices[hi] = i;
    }
    free(keys);
    free(indices);
    *returnSize = 0;
    return NULL;
}