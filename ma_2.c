#include <stdio.h>
#include <time.h>

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
    clock_t start, end;
    double time_spent;
    
    init_matrix_blocked(A, 0);
    init_matrix_blocked(B, 1);
    init_matrix_blocked(C, 2);
    
    start = clock();
    
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Matrix addition took: %f seconds\n", time_spent);
    
    return 0;
}