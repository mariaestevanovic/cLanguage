#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    // If the number is less than or equal to 1, it is not prime
    if (num <= 1) {
        return false;
    }
    // Check if the number is divisible by any number between 2 and the square root of the number
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Main function
int main() {
    int n = 100;
    bool primes[n + 1];

    // Initialize the primes array with true
    for (int i = 0; i <= n; i++) {
        primes[i] = true;
    }

    // Mark non-prime numbers as false
    primes[0] = primes[1] = false;

    // Check if the number is prime and mark its multiples as non-prime
    for (int p = 2; p * p <= n; p++) {
        if (primes[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    printf("Prime numbers from 0 to %d:\n", n);
    // Print all prime numbers from 0 to n
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
