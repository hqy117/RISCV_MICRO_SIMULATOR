#include <stdio.h>

#define ITERATIONS 1000000

int main() {
    int sum = 0;
    
    asm("csrs 0x800,zero");
    
    for(int i = 0; i < ITERATIONS; i++) {
        if(i % 100 == 97) {
            continue;
        }
        sum += i;
    }
    
    asm("csrs 0x801,zero");
    
    return 0;
}