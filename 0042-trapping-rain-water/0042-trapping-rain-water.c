int trap(int* height, int heightSize) {
    if (heightSize <= 2) {
        return 0;
    }

    int left = 0;
    int right = heightSize - 1;
    int left_max = height[left];
    int right_max = height[right];
    int total_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            left++;
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                total_water += left_max - height[left];
            }
        } else {
            right--;
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                total_water += right_max - height[right];
            }
        }
    }

    return total_water;
}