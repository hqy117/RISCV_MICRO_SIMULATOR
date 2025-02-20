#include <stdio.h>

#define ITERATIONS 1000000

int main() {
    int sum = 0;
    
    asm("csrs 0x800,zero");  // Start monitoring
    
    for(int i = 0; i < ITERATIONS; i++) {
        if(i % 2 == 0) {
            sum += 1;
        }
    }
    
    asm("csrs 0x801,zero");  // Stop monitoring
    
    return 0;
}