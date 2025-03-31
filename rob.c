#include <stdio.h>

#define N 1000

double A[N], B[N], C[N];

int main() {
    // Initialize arrays
    for (int i = 0; i < N; i++) {
        A[i] = i * 1.0;
        B[i] = (N - i) * 1.0;
    }

    asm("csrs 0x800, zero");  // Start performance monitoring

    // Main computation loop
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
        A[i] = A[i] * 1.1;
        B[i] = B[i] - 0.9;
    }

    asm("csrs 0x801, zero");  // Stop performance monitoring

    return 0;
}

