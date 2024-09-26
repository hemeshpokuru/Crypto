#include<stdio.h>
#include<string.h>

int main(){
    unsigned int a[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};  // Encryption matrix
    unsigned int b[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};    // Decryption matrix
    unsigned int c[20], d[20];  // Arrays to store transformed values
    char msg[20];               // Message input
    int i, j, t = 0;

    printf("Enter 3-character plaintext (uppercase only):\n");
    scanf("%s", msg);

    if(strlen(msg) != 3) {
        printf("Error: Plaintext must be exactly 3 characters long.\n");
        return 1;
    }

    // Convert plaintext characters to numbers (A=0, B=1, ..., Z=25)
    for(i = 0; i < strlen(msg); i++) {
        c[i] = msg[i] - 65;  // ASCII value conversion
        printf("%d ", c[i]); // Show numeric equivalent
    }

    // Encryption: Multiply the message vector with matrix 'a'
    for(i = 0; i < 3; i++) {
        t = 0;
        for(j = 0; j < 3; j++) {
            t = t + (a[i][j] * c[j]);
        }
        d[i] = t % 26;  // Modulo 26 operation
    }

    // Print encrypted cipher text
    printf("\nEncrypted Cipher Text :");
    for(i = 0; i < 3; i++) {
        printf(" %c", d[i] + 65);  // Convert numbers back to characters
    }

    // Decryption: Multiply the cipher text vector with matrix 'b'
    for(i = 0; i < 3; i++) {
        t = 0;
        for(j = 0; j < 3; j++) {
            t = t + (b[i][j] * d[j]);
        }
        c[i] = t % 26;  // Modulo 26 operation
    }

    // Print decrypted plain text
    printf("\nDecrypted Cipher Text :");
    for(i = 0; i < 3; i++) {
        printf(" %c", c[i] + 65);  // Convert numbers back to characters
    }

    return 0;
}

