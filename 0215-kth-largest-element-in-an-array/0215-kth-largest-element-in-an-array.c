static inline void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int target = numsSize - k;
    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {
        // Median-of-three pivot
        int mid = left + ((right - left) >> 1);

        if (nums[left] > nums[mid])
            swap(&nums[left], &nums[mid]);

        if (nums[left] > nums[right])
            swap(&nums[left], &nums[right]);

        if (nums[mid] > nums[right])
            swap(&nums[mid], &nums[right]);

        int pivot = nums[mid];

        // Dutch National Flag Partition
        int lt = left;
        int i = left;
        int gt = right;

        while (i <= gt)
        {
            if (nums[i] < pivot)
            {
                swap(&nums[i], &nums[lt]);
                i++;
                lt++;
            }
            else if (nums[i] > pivot)
            {
                swap(&nums[i], &nums[gt]);
                gt--;
            }
            else
            {
                i++;
            }
        }

        if (target < lt)
        {
            right = lt - 1;
        }
        else if (target > gt)
        {
            left = gt + 1;
        }
        else
        {
            return nums[target];
        }
    }

    return -1;
}