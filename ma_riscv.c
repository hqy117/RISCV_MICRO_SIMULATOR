#include <stdio.h>

#define N 2048
#define BLOCK_SIZE 128

static double A[N][N];
static double B[N][N];
static double C[N][N];

void init_matrix_blocked(double M[N][N], int mode) {
    int ii, jj, i, j;
    for (ii = 0; ii < N; ii += BLOCK_SIZE) {
        for (jj = 0; jj < N; jj += BLOCK_SIZE) {
            for (i = ii; i < (ii + BLOCK_SIZE < N ? ii + BLOCK_SIZE : N); i++) {
                for (j = jj; j < (jj + BLOCK_SIZE < N ? jj + BLOCK_SIZE : N); j++) {
                    if (mode == 0)
                        M[i][j] = i + j;
                    else if (mode == 1)
                        M[i][j] = i - j;
                    else
                        M[i][j] = 0.0;
                }
            }
        }
    }
}

int main(void) {
    int i, j;
    
    init_matrix_blocked(A, 0);
    init_matrix_blocked(B, 1);
    init_matrix_blocked(C, 2);
    
    asm("csrs 0x800,zero");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    asm("csrs 0x801,zero");
    
    return 0;
}