#include <stdio.h>
#include <stdlib.h>

// to write a c program to swap two numbers

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // int a = 10, b = 20;
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}