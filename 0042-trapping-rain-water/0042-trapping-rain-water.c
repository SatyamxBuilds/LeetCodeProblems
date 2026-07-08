int trap(int* height, int heightSize) {
    if (heightSize == 0) return 0;

    int left = 0, right = heightSize - 1;
    int left_max = height[0], right_max = height[heightSize - 1];
    int water = 0;

    while (left < right) {
        if (left_max < right_max) {
            left++;
            if (height[left] > left_max) left_max = height[left];
            else water += left_max - height[left];
        } else {
            right--;
            if (height[right] > right_max) right_max = height[right];
            else water += right_max - height[right];
        }
    }

    return water;
}