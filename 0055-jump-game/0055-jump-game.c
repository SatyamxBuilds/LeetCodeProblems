#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        // If current index is beyond the farthest reachable point
        if (i > maxReach)
            return false;

        // Update the farthest reachable index
        if (i + nums[i] > maxReach)
            maxReach = i + nums[i];

        // If we can already reach or pass the last index
        if (maxReach >= numsSize - 1)
            return true;
    }

    return true;
}