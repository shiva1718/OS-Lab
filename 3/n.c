// concatenation of 2 strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[100];
    int i, j, len1, len2;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    for (i = 0; i < len1; i++) {
        str3[i] = str1[i];
    }

    for (j = 0; j < len2; j++) {
        str3[i + j] = str2[j];
    }

    str3[i + j] = '\0';

    printf("Concatenated string: %s\n", str3);

    return 0;
}