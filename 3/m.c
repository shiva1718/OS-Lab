// check if given string is palindrome or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, flag;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    flag = 1;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        printf("String is palindrome\n");
    } else {
        printf("String is not palindrome\n");
    }

    return 0;
}