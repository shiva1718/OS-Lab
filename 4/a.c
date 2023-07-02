#include <stdio.h>
#include <stdlib.h>

// to write a c program to find the biggest amoung a list of numbers
double findLargest(int n, double nums[]) {
    double largest = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }
    return largest;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    double nums[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &nums[i]);
    }
    printf("The largest element is %lf\n", findLargest(n, nums));
    return 0;
}