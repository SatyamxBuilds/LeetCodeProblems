#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32768

typedef struct
{
    int key;
    int index;
    unsigned char used;
} Entry;

static Entry table[HASH_SIZE];

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    memset(table, 0, sizeof(table));

    for (int i = 0; i < numsSize; ++i)
    {
        int need = target - nums[i];
        unsigned int h = ((unsigned int)need) & (HASH_SIZE - 1);

        while (table[h].used)
        {
            if (table[h].key == need)
            {
                int *ans = (int*)malloc(sizeof(int) * 2);
                ans[0] = table[h].index;
                ans[1] = i;
                *returnSize = 2;
                return ans;
            }
            h = (h + 1) & (HASH_SIZE - 1);
        }

        h = ((unsigned int)nums[i]) & (HASH_SIZE - 1);

        while (table[h].used)
            h = (h + 1) & (HASH_SIZE - 1);

        table[h].used = 1;
        table[h].key = nums[i];
        table[h].index = i;
    }

    *returnSize = 0;
    return NULL;
}