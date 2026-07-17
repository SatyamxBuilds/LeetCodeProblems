#pragma GCC optimize("O3")

int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
    static long long freq[50005];
    static long long countDivisor[50005];
    static long long prefixGcd[50005];

    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    for (int i = 0; i <= maxVal; i++) {
        freq[i] = 0;
        countDivisor[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    for (int i = 1; i <= maxVal; ++i) {
        for (int j = i; j <= maxVal; j += i) {
            countDivisor[i] += freq[j];
        }
    }

    for (int i = maxVal; i >= 1; --i) {
        long long totalPairs = (countDivisor[i] * (countDivisor[i] - 1)) >> 1;
        for (int j = 2 * i; j <= maxVal; j += i) {
            totalPairs -= countDivisor[j];
        }
        countDivisor[i] = totalPairs;
    }

    prefixGcd[0] = 0;
    for (int i = 1; i <= maxVal; ++i) {
        prefixGcd[i] = prefixGcd[i - 1] + countDivisor[i];
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

    return result;
}