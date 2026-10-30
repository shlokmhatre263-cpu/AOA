#include <stdio.h>
#include <string.h>

int match(char st[100], char pat[100]);

int main() {
    char st[100], pat[100];
    int status;

    printf("*** Naive String Matching Algorithm ***\n");

    printf("Enter the String:\n");
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = '\0';

    printf("Enter the pattern to match:\n");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';

    status = match(st, pat);

    if (status == -1)
        printf("\nNo match found");
    else
        printf("Match has been found at %d position.", status);

    return 0;
}

int match(char st[100], char pat[100]) {
    int n, m, i, j, count = 0, temp = 0;

    n = strlen(st);
    m = strlen(pat);

    for (i = 0; i <= n - m; i++) {
        temp++;

        for (j = 0; j < m; j++) {
            if (st[i + j] == pat[j])
                count++;
            else
                break;
        }

        if (count == m)
            return temp;

        count = 0;
    }

    return -1;
}