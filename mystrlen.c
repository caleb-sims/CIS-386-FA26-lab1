

#include <stddef.h>
#include <stdio.h>

size_t my_strlen(const char *str);

int main(int argc, char *argv[]) {
    
    // if (argc < 2) {
    //     printf("usage: %s <word>\n", argv[0]);
    //     return 1;
    // }

    char str[100];

    printf("Input: ");
    scanf("%s", &str);

    printf("Length: %zu\n", my_strlen(str));
    
    return 0;
}

size_t my_strlen(const char *str) {
    const char *start = str;
    const char *end = str;

    while (*end != '\0') {
        end++;
    }

    return end - start;
}