#pragma GCC optimize("O3")

int largestRectangleArea(int* heights, int heightsSize) {
    static int stack[100005];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int currentHeight = (i == heightsSize) ? 0 : heights[i];

        while (top != -1 && heights[stack[top]] >= currentHeight) {
            int h = heights[stack[top--]];
            int w = (top == -1) ? i : (i - stack[top] - 1);
            int area = h * w;
            if (area > maxArea) {
                maxArea = area;
            }
        }
        stack[++top] = i;
    }

    return maxArea;
}