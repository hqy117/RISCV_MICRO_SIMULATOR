#include <stdio.h>

int main()
{
  asm("csrs 0x800,zero");  // SIM_START
  printf("Hello RISC-V World\n");
  asm("csrs 0x801,zero");  // SIM_STOP
  return 0;
}
