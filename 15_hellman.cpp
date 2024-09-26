#include <stdio.h>

// Function to calculate (a^b) % mod using recursive modular exponentiation
long long int power(int a, int b, int mod) {
    long long int t;
    if(b == 1)
        return a;
    
    t = power(a, b / 2, mod);  // Divide and conquer approach
    
    if(b % 2 == 0)
        return (t * t) % mod;  // If b is even
    else
        return (((t * t) % mod) * a) % mod;  // If b is odd
}

// Function to calculate the key using modular exponentiation
long int calculateKey(int a, int x, int n) {
    return power(a, x, n);
}

int main() {
    int n, g, x, a, y, b;

    // Input public values n and g
    printf("Enter the value of n (a large prime number) and g (a primitive root): ");
    scanf("%d%d", &n, &g);

    // Input private value x for the first person
    printf("Enter the value of x (private key for the first person): ");
    scanf("%d", &x);

    // Calculate public key a for the first person
    a = power(g, x, n);
    
    // Input private value y for the second person
    printf("Enter the value of y (private key for the second person): ");
    scanf("%d", &y);

    // Calculate public key b for the second person
    b = power(g, y, n);

    // Calculate the shared secret key for both persons
    printf("Key for the first person is: %lld\n", power(b, x, n));
    printf("Key for the second person is: %lld\n", power(a, y, n));

    return 0;
}

