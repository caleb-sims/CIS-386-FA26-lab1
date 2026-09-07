#include <stdio.h>
#include <stdlib.h>

void reverse_in_place(int *arr[], size_t length);
int* reverse_out_of_place(int *arr[], size_t length);

int main(void) {
    size_t length;
    printf("Enter length of array: ");
    scanf("%zu", &length);

    int *arr[length];
    printf("Enter %zu integers: ", length);
    for (size_t i = 0; i < length; i++) {
        arr[i] = malloc(sizeof(int));
        scanf("%d", arr[i]);
    }

    printf("Original array: ");
    for (size_t i = 0; i < length; i++) {
        printf("%d ", *arr[i]);
    }
    printf("\n");

    printf("Reversed array (out of place): ");
    int *reversed = reverse_out_of_place(arr, length);
    for (size_t i = 0; i < length; i++) {
        printf("%d ", reversed[i]);
    }
    printf("\n");
    free(reversed);

    printf("Original array: ");
    for (size_t i = 0; i < length; i++) {
        printf("%d ", *arr[i]);
    }
    printf("\n");

    printf("Reversed array (in place): ");
    reverse_in_place(arr, length);
    for (size_t i = 0; i < length; i++) {
        printf("%d ", *arr[i]);
    }
    printf("\n");

    for (size_t i = 0; i < length; i++) {
        free(arr[i]);
    }

    return 0;
}

void reverse_in_place(int *arr[], size_t length) {
    int **left = arr;
    int **right = arr + length - 1;

    while (left < right) {
        int *temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int* reverse_out_of_place(int *arr[], size_t length) {
    int *reversed = malloc(length * sizeof(int));

    for (size_t i = 0; i < length; i++) {
        reversed[i] = *arr[length - 1 - i];
    }

    return reversed;
}