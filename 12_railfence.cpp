#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k, l;
    char a[20], c[20], d[20];

    printf("\n\t\t RAIL FENCE TECHNIQUE");

    printf("\n\nEnter the input string: ");
    fgets(a, sizeof(a), stdin);  // Using fgets instead of gets for safer input
    a[strcspn(a, "\n")] = '\0';  // Remove newline character from input if present

    l = strlen(a);

    // Ciphering
    for(i = 0, j = 0; i < l; i++) {
        if(i % 2 == 0) {
            c[j++] = a[i];  // Take characters at even indices first
        }
    }
    for(i = 0; i < l; i++) {
        if(i % 2 == 1) {
            c[j++] = a[i];  // Then take characters at odd indices
        }
    }
    c[j] = '\0';

    printf("\nCipher text after applying rail fence: ");
    printf("\n%s", c);

    // Deciphering
    if(l % 2 == 0)
        k = l / 2;  // Split at the middle for even length
    else
        k = (l / 2) + 1;  // Slightly offset the split for odd length

    for(i = 0, j = 0; i < k; i++) {
        d[j] = c[i];  // Fill even index characters
        j = j + 2;
    }
    for(i = k, j = 1; i < l; i++) {
        d[j] = c[i];  // Fill odd index characters
        j = j + 2;
    }
    d[l] = '\0';

    printf("\nText after decryption: ");
    printf("%s\n", d);
}

