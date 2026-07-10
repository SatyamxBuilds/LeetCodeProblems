int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxWater = 0;
    while (left < right) {
        int hL = height[left];
        int hR = height[right];
        int currentHeight = hL < hR ? hL : hR;
        int currentWater = currentHeight * (right - left);
        if (currentWater > maxWater) {
            maxWater = currentWater;
        }
        if (hL < hR) {
            while (left < right && height[left] <= hL) {
                left++;
            }
        } else {
            while (left < right && height[right] <= hR) {
                right--;
            }
        }
    }
    return maxWater;
}