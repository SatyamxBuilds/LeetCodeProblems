#pragma GCC optimize("O3")

int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    long long* freq = (long long*)calloc(maxVal + 1, sizeof(long long));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    long long* countDivisor = (long long*)calloc(maxVal + 1, sizeof(long long));
    for (int i = 1; i <= maxVal; ++i) {
        for (int j = i; j <= maxVal; j += i) {
            countDivisor[i] += freq[j];
        }
    }

    long long* gcdPairs = (long long*)calloc(maxVal + 1, sizeof(long long));
    for (int i = maxVal; i >= 1; --i) {
        long long totalPairs = (countDivisor[i] * (countDivisor[i] - 1)) >> 1;
        for (int j = 2 * i; j <= maxVal; j += i) {
            totalPairs -= gcdPairs[j];
        }
        gcdPairs[i] = totalPairs;
    }

    long long* prefixGcd = (long long*)calloc(maxVal + 1, sizeof(long long));
    for (int i = 1; i <= maxVal; ++i) {
        prefixGcd[i] = prefixGcd[i - 1] + gcdPairs[i];
    }

    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        long long q = queries[i];
        int low = 1, high = maxVal;
        int answer = maxVal;
        
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (prefixGcd[mid] > q) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        result[i] = answer;
    }

    free(freq);
    free(countDivisor);
    free(gcdPairs);
    free(prefixGcd);

    return result;
}