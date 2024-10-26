#include <stdio.h>

// Function to calculate trapped rain water
int trap(int* height, int heightSize) {
    if (heightSize == 0) return 0;

    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }
    return water;
}

int main() {
    int height[] = {4, 2, 0, 3, 2, 5};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int result = trap(height, heightSize);
    printf("Trapped rain water: %d\n", result);

    return 0;
}
