#include <stdio.h>
#include <string.h>

// Function to create the Playfair matrix
void createPlayfairMatrix(char key[], char matrix[5][5]) {
    int used[26] = {0}; // To track used letters
    int k = 0;

    // Add the key letters to the matrix
    for (int i = 0; i < strlen(key); i++) {
        if (key[i] != 'J' && !used[key[i] - 'A']) {
            matrix[k / 5][k % 5] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }

    // Fill the remaining matrix with the unused letters
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J' && !used[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            k++;
        }
    }
}

// Function to find the coordinates of a character in the matrix
void findCoordinates(char matrix[5][5], char c, int *row, int *col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt the message using Playfair cipher
void encryptMessage(char matrix[5][5], char message[], char encrypted[]) {
    int i = 0, e = 0;

    while (i < strlen(message)) {
        char c1 = message[i];
        char c2 = (i + 1 < strlen(message)) ? message[i + 1] : 'X'; // Padding if needed
        int r1, c1_index, r2, c2_index;

        if (c1 == c2) {
            c2 = 'X'; // Add padding if both characters are the same
        }

        findCoordinates(matrix, c1, &r1, &c1_index);
        findCoordinates(matrix, c2, &r2, &c2_index);

        if (r1 == r2) {
            // Same row, shift right
            encrypted[e++] = matrix[r1][(c1_index + 1) % 5];
            encrypted[e++] = matrix[r2][(c2_index + 1) % 5];
        } else if (c1_index == c2_index) {
            // Same column, shift down
            encrypted[e++] = matrix[(r1 + 1) % 5][c1_index];
            encrypted[e++] = matrix[(r2 + 1) % 5][c2_index];
        } else {
            // Rectangle swap
            encrypted[e++] = matrix[r1][c2_index];
            encrypted[e++] = matrix[r2][c1_index];
        }

        i += 2; // Move to the next pair of characters
    }
    encrypted[e] = '\0'; // Null terminate the encrypted message
}

int main() {
    char key[] = "MFHIJKUNOPQZVWXYELARGDSTBC";
    char matrix[5][5];
    char message[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    char encrypted[100];

    createPlayfairMatrix(key, matrix);
    encryptMessage(matrix, message, encrypted);

    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", encrypted);

    return 0;
}

