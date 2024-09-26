#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generate_cipher_sequence(const char *keyword, char *cipher_sequence) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int used[26] = {0};
    int index = 0;
    for (int i = 0; i < strlen(keyword); i++) {
        char upper_char = toupper(keyword[i]);
        if (!used[upper_char - 'A']) {
            cipher_sequence[index++] = upper_char;
            used[upper_char - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!used[i]) {
            cipher_sequence[index++] = alphabet[i];
        }
    }
    cipher_sequence[index] = '\0';
}
void encrypt(const char *plain_text, const char *cipher_sequence, char *encrypted_text) {
    int i;
    for (i = 0; i < strlen(plain_text); i++) {
        char upper_char = toupper(plain_text[i]);
        if (isalpha(upper_char)) {
            int index = upper_char - 'A';
            encrypted_text[i] = cipher_sequence[index];
        } else {
            encrypted_text[i] = plain_text[i];
        }
    }
    encrypted_text[i] = '\0';
}
void decrypt(const char *encrypted_text, const char *cipher_sequence, char *decrypted_text) {
    int i;
    for (i = 0; i < strlen(encrypted_text); i++) {
        char upper_char = toupper(encrypted_text[i]);
        if (isalpha(upper_char)) {
            int index = strchr(cipher_sequence, upper_char) - cipher_sequence;
            decrypted_text[i] = 'A' + index;
        } else {
            decrypted_text[i] = encrypted_text[i];
        }
    }
    decrypted_text[i] = '\0';
}
int main() {
    char keyword[] = "CIPHER";
    char cipher_sequence[27];
    generate_cipher_sequence(keyword, cipher_sequence);
    char plain_text[] = "cse";
    char encrypted_text[100];
    char decrypted_text[100];

    encrypt(plain_text, cipher_sequence, encrypted_text);
    decrypt(encrypted_text, cipher_sequence, decrypted_text);

    printf("Plain Text: %s\n", plain_text);
    printf("Cipher: %s\n", encrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}

