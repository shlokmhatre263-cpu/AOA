#include <stdio.h>
#include <string.h>

void computeLPSArray(char pat[], int M, int lps[]) {
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char pat[], char txt[]) {
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    int i = 0;
    int j = 0;

    computeLPSArray(pat, M, lps);

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char txt[] = "THIS IS TEST TEXT";
    char pat[] = "TEXT";

    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);

    KMPSearch(pat, txt);

    return 0;
}