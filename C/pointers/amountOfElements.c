#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Counts the number of even elements in an array
int countEvenElements(int *arr, int size) {
  // Initialize the count variable to 0
  int count = 0;
  // Loop through the array
  for (int i = 0; i < size; i++) {
    // Check if the element is even
    if (arr[i] % 2 == 0) {
      // Increment the count variable if the element is even
      count++;
    }
  }
  // Return the count of even elements
  return count;
}

// Main function
int main() {
  // Declare the variable n with the value 10, which represents the size of the array
  int n = 10;
  // Declare a pointer to an integer that will be used to store the array
  int *arr;

  // Allocate memory for an array of n elements
  arr = (int *)malloc(n * sizeof(int));

  // Check if memory allocation was successful
  if (arr == NULL) {
    printf("Memory allocation error\n");
    return 1;
  }

  // Fill the array with values provided by the user
  printf("Enter 10 integers:\n");
  for (int i = 0; i < n; i++) {
    // Loop through the array, prompting the user to enter values
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  // Call the countEvenElements function, passing the array pointer and the size of the array as arguments
  int evenCount = countEvenElements(arr, n);
  printf("Number of even elements: %d\n", evenCount);

  // Free the allocated memory
  free(arr);

  return 0;
}
