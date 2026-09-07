#include <stdio.h>
#include <stdlib.h>

int findMax(int *arr[], int n);

int main(void) {
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    int *arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(sizeof(int));
        scanf("%d", arr[i]);
    }

    findMax(arr, n);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    return 0;
}

int findMax(int *arr[], int n) {
    int max = *arr[0];
    for (int i = 1; i < n; i++) {
        if (*arr[i] > max) {
            max = *arr[i];
        }
    }

    int min = *arr[0];
    for (int i = 1; i < n; i++) {
        if (*arr[i] < min) {
            min = *arr[i];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *arr[i];
    }

    double average = (double)sum / n;

    // print max, min, sum, average (rounded to 5 decimal places)
    printf("max: %d\n", max);
    printf("min: %d\n", min);
    printf("sum: %d\n", sum);
    printf("average: %.5f\n", average);
    return 0;
}