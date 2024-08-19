#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the length of each element in an array of strings
int* getStringLengths(char **arr, int size) {
    // Allocate an array of integers to store the lengths
    int *lengths = (int *)malloc(size * sizeof(int));
    if (lengths == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    // Traverse the array of strings and calculate the length of each element
    for (int i = 0; i < size; i++) {
        lengths[i] = strlen(arr[i]);
    }
    return lengths;
}

int main() {
    int n;
    char **arr;
    int *lengths;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Allocate an array of strings
    arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        // Allocate memory for each string (up to 100 characters)
        arr[i] = (char *)malloc(100 * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation error\n");
            for (int j = 0; j < i; j++) {
                // Free the memory allocated for previous strings
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
        printf("Enter string %d: ", i + 1);
        // Read the string from the user
        scanf("%s", arr[i]);
    }

    // Get the lengths of the strings
    lengths = getStringLengths(arr, n);
    if (lengths == NULL) {
        for (int i = 0; i < n; i++) {
            free(arr[i]);
        }
        free(arr);
        return 1;
    }

    // Display the lengths of the strings
    printf("Lengths of the strings:\n");
    for (int i = 0; i < n; i++) {
        printf("String %d: %s (Length: %d)\n", i + 1, arr[i], lengths[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(lengths);

    return 0;
}
