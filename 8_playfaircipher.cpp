#include <stdio.h>
#include <string.h>

// Function to decrypt the Playfair cipher
void decryptPlayfair(char message[], char key[]) {
    int i, j;
    char matrix[5][5];
    int keyIndex = 0;
    int used[26] = {0};  // To keep track of used characters

    // Fill the matrix with the key
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // If the character is not used yet and not 'J', add it to the matrix
            if (!used[key[keyIndex] - 'A'] && key[keyIndex] != 'J') {
                matrix[i][j] = key[keyIndex];
                used[key[keyIndex] - 'A'] = 1;
            }
            keyIndex++;
        }
    }

    // Decrypt the message in pairs
    for (i = 0; i < strlen(message); i += 2) {
        char c1 = message[i];
        char c2 = message[i + 1];
        int r1, c1_index, r2, c2_index;

        // Find the positions of the characters in the matrix
        for (j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (matrix[j][k] == c1) {
                    r1 = j;
                    c1_index = k;
                }
                if (matrix[j][k] == c2) {
                    r2 = j;
                    c2_index = k;
                }
            }
        }

        // Decrypt according to Playfair rules
        if (r1 == r2) {
            // Same row, shift left
            printf("%c%c", matrix[r1][(c1_index + 4) % 5], matrix[r2][(c2_index + 4) % 5]);
        } else if (c1_index == c2_index) {
            // Same column, shift up
            printf("%c%c", matrix[(r1 + 4) % 5][c1_index], matrix[(r2 + 4) % 5][c2_index]);
        } else {
            // Rectangle swap
            printf("%c%c", matrix[r1][c2_index], matrix[r2][c1_index]);
        }
    }

    printf("\n");
}

int main() {
    char message[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char key[] = "PLAYFIREXMBCDGHKNOQSTUVWZ";

    decryptPlayfair(message, key);
    return 0;
}

