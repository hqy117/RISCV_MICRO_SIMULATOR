#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define ITERATIONS 5

void matrix_multiply_simple(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void initialize_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Add function to print a small section of the matrix
void print_matrix_section(int matrix[SIZE][SIZE], const char* name) {
    printf("\nFirst 5x5 elements of matrix %s:\n", name);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int (*A)[SIZE] = malloc(SIZE * SIZE * sizeof(int));
    int (*B)[SIZE] = malloc(SIZE * SIZE * sizeof(int));
    int (*C)[SIZE] = malloc(SIZE * SIZE * sizeof(int));

    // Initialize matrices
    srand(42);  // Set seed for reproducible results
    initialize_matrix(A);
    initialize_matrix(B);

    // Print initial sections
    print_matrix_section(A, "A");
    print_matrix_section(B, "B");

    printf("\nRunning simple matrix multiplication...\n");
    for (int i = 0; i < ITERATIONS; i++) {
        matrix_multiply_simple(A, B, C);
        printf("Iteration %d completed\n", i + 1);
    }

    // Print result section
    print_matrix_section(C, "C (result)");

    free(A);
    free(B);
    free(C);
    return 0;
}