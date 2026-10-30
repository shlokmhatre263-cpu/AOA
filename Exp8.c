#include <stdio.h>
#include <stdlib.h> // for abs()

#define N 4

int q[N]; // q[row] = column of queen in that row

// Check if we can place queen at row r, column c
int safe(int r, int c) {
    for(int i = 0; i < r; i++) {
        // check same column or same diagonal
        if(q[i] == c || abs(q[i] - c) == abs(r - i))
            return 0; // conflict
    }
    return 1; // safe
}

// Place queens row by row
void place(int row) {
    if(row == N) { // all queens placed
        // print solution
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(q[i]==j) printf("Q ");
                else printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for(int col=0; col<N; col++) {
        if(safe(row, col)) {
            q[row] = col;   // place queen
            place(row+1);   // next row
        }
    }
}

int main() {
    printf("All solutions for 4-Queens:\n\n");
    place(0); // start placing from row 0
    return 0;
}