#include <stdio.h>
#include <string.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function implementing your algorithm and printing the subsequence
void LCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);

    // Creating the table L[m+1][n+1]
    int L[m + 1][n + 1];

    // 1. Fill the DP table exactly as per your algorithm
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // L[m][n] contains the length of the LCS
    int index = L[m][n];
    printf("Length of LCS: %d\n", index);

    // 2. Backtrack from L[m][n] to reconstruct the actual string
    char lcs_result[index + 1];
    lcs_result[index] = '\0'; // Set the null terminator for the string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current characters match, they are part of the LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs_result[index - 1] = X[i - 1]; // Put the character in the result array
            i--;
            j--;
            index--; // Move diagonally up-left
        }
        // If they don't match, move in the direction of the larger value
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    // Print the final reconstructed subsequence
    printf("Longest Common Subsequence: %s\n", lcs_result);
}

int main() {
    char X[100];
    char Y[100];

    // Taking inputs from the user
    printf("Enter the first string: ");
    scanf("%99s", X);

    printf("Enter the second string: ");
    scanf("%99s", Y);

    // Executing the algorithm
    LCS(X, Y);

    return 0;
}