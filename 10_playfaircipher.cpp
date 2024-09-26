#include <stdio.h>
#include <string.h>

// Function to calculate factorial of a number
unsigned long long factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int keyLength = 25;  // Length of the key
    
    // Calculate total possible keys (factorial of key length)
    unsigned long long totalPossibleKeys = factorial(keyLength);

    // Display the total possible keys (before considering identical encryption results)
    printf("Total possible keys (without considering identical encryption results): %llu\n", totalPossibleKeys);

    // Calculate effectively unique keys (by dividing by key length)
    unsigned long long effectivelyUniqueKeys = totalPossibleKeys / keyLength;

    // Display effectively unique keys (after considering identical encryption results)
    printf("Effectively unique keys (considering identical encryption results): %llu\n", effectivelyUniqueKeys);

    return 0;
}

