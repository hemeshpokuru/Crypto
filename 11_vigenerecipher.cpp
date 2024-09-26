#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>  // For exit()

void encipher();
void decipher();

int main() {
    int choice;
    while(1) {
        printf("\n1. Encrypt Text");
        printf("\t2. Decrypt Text");
        printf("\t3. Exit");
        printf("\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        if(choice == 3) {
            exit(0);  // Exit the program
        } else if(choice == 1) {
            encipher();  // Call encipher function
        } else if(choice == 2) {
            decipher();  // Call decipher function
        } else {
            printf("Please Enter a Valid Option.\n");
        }
    }
    return 0;
}

void encipher() {
    unsigned int i, j;
    char input[50], key[10];

    printf("\n\nEnter Plain Text: ");
    scanf("%s", input);

    printf("\nEnter Key Value: ");
    scanf("%s", key);

    printf("\nResultant Cipher Text: ");
    for(i = 0, j = 0; i < strlen(input); i++, j++) {
        if(j >= strlen(key)) {
            j = 0;  // Repeat the key when it runs out
        }

        // Convert both input and key characters to uppercase and shift accordingly
        char cipher_char = 65 + (((toupper(input[i]) - 65) + (toupper(key[j]) - 65)) % 26);
        printf("%c", cipher_char);  // Print the encrypted character
    }
    printf("\n");
}

void decipher() {
    unsigned int i, j;
    char input[50], key[10];

    printf("\n\nEnter Cipher Text: ");
    scanf("%s", input);

    printf("\nEnter the Key Value: ");
    scanf("%s", key);

    printf("\nDecrypted Plain Text: ");
    for(i = 0, j = 0; i < strlen(input); i++, j++) {
        if(j >= strlen(key)) {
            j = 0;  // Repeat the key when it runs out
        }

        // Convert both input and key characters to uppercase
        int value = (toupper(input[i]) - 65) - (toupper(key[j]) - 65);

        // Handle negative values correctly by adding 26 before the modulo
        if(value < 0) {
            value += 26;
        }

        printf("%c", 65 + (value % 26));  // Print the decrypted character
    }
    printf("\n");
}

