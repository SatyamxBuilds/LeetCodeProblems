double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        int* tmp = nums1; nums1 = nums2; nums2 = tmp;
        int tmpSize = nums1Size; nums1Size = nums2Size; nums2Size = tmpSize;
    }

    int m = nums1Size, n = nums2Size;
    int low = 0, high = m;
    int halfLen = (m + n + 1) / 2;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = halfLen - i;

        int nums1LeftMax  = (i == 0) ? INT_MIN : nums1[i - 1];
        int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
        int nums2LeftMax  = (j == 0) ? INT_MIN : nums2[j - 1];
        int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

        if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
            if ((m + n) % 2 == 0) {
                int leftMax = (nums1LeftMax > nums2LeftMax) ? nums1LeftMax : nums2LeftMax;
                int rightMin = (nums1RightMin < nums2RightMin) ? nums1RightMin : nums2RightMin;
                return (leftMax + rightMin) / 2.0;
            } else {
                return (double)((nums1LeftMax > nums2LeftMax) ? nums1LeftMax : nums2LeftMax);
            }
        } else if (nums1LeftMax > nums2RightMin) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }

    return 0.0;
}