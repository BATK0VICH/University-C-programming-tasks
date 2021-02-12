/*
TI-202 F/R
Dmitrii Dronov
24.09.2020
Lucrarea Laborator N5
Count words in string
Variant 10
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUF 128

int main(void) {
        char *str = (char *)malloc(sizeof(char) * BUF);
        printf("Enter your string: ");
        fgets(str, BUF, stdin);

        printf("Enter a char: ");
        char ch;
        scanf("%c", &ch);

        int caseSensetive = 0;
        int wordCount = 0;

        //iterate str
        for (int i = 0; i < BUF; ++i) {
            if (str[i] == ch && (i == 0 || str[i - 1] == ' '))
                ++caseSensetive;
            if (toupper(str[i]) == toupper(ch) && (i == 0 || str[i - 1] == ' '))
                ++wordCount;
        }

        printf("Case sensetive: %d\nCase insensetive: %d\n", caseSensetive, wordCount);
        free(str);
    return 0;
}