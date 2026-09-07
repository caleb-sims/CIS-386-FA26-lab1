#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeChar(char *str, char c) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void toLower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int isPalindrome(char *str) {
    toLower(str);
    removeChar(str, ' ');
    removeChar(str, ',');
    removeChar(str, '.');
    removeChar(str, '!');
    removeChar(str, '?');
    removeChar(str, '\'');
    removeChar(str, '"');

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

int main(void) {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    if (isPalindrome(str)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}