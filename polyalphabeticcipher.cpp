#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    char plaintext[256];
    char key[256];
    char ciphertext[256];
    char decrypted[256];
    
    int key_index = 0;
    
    // Input plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character
    
    // Input key
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character
    
    int key_length = strlen(key);
    int text_length = strlen(plaintext);
    
    // Encryption
    for (int i = 0; i < text_length; i++) {
        char current_char = plaintext[i];

        if (isalpha(current_char)) {
            char base = isupper(current_char) ? 'A' : 'a';
            char normalized_char = tolower(current_char) - 'a';
            char normalized_key = tolower(key[key_index % key_length]) - 'a';

            char encrypted_char = (normalized_char + normalized_key) % ALPHABET_SIZE + 'a';
            ciphertext[i] = isupper(current_char) ? toupper(encrypted_char) : encrypted_char;

            key_index++;
        } else {
            ciphertext[i] = current_char; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[text_length] = '\0'; // Null terminate the string

    // Output ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    key_index = 0; // Reset key_index for decryption

    // Decryption
    for (int i = 0; i < text_length; i++) {
        char current_char = ciphertext[i];

        if (isalpha(current_char)) {
            char base = isupper(current_char) ? 'A' : 'a';
            char normalized_char = tolower(current_char) - 'a';
            char normalized_key = tolower(key[key_index % key_length]) - 'a';

            char decrypted_char = (normalized_char - normalized_key + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
            decrypted[i] = isupper(current_char) ? toupper(decrypted_char) : decrypted_char;

            key_index++;
        } else {
            decrypted[i] = current_char; // Non-alphabetic characters remain unchanged
        }
    }
    decrypted[text_length] = '\0'; // Null terminate the string

    // Output decrypted text
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
