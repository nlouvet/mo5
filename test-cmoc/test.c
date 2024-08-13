#include "cmoc.h"

#define POKE(addr,val)     (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val)    (*(unsigned*) (addr) = (val))

void PLOT(unsigned int x, unsigned int y) {
  asm {
    ldx :x
    ldy :y
    swi
    .byte 0x10
  }
}

void LINE(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1) {
  POKEW(0x2032, x0);
  POKEW(0x2034, y0);
  asm {
    ldx :x1
    ldy :y1
    swi
    .byte 0x0E
  }
}

void primes(unsigned int n) {
  unsigned int i, j;
  printf("Prime numbers less than %d\r\n", n);
  for(i = 1; i < n; i++) {
    for(j = 2; j < i; j++) {
      if(i % j == 0) break;
    }
    if(j == i) printf("%d ", i);
  }
  printf("\r\n");
}

#define NMAX 2000

void sieve(unsigned int n) {
  unsigned char s[NMAX];
  unsigned int i, j;
  
  if(n > NMAX) n = NMAX;
  
  printf("Sieving prime numbers less than %d...\r\n", n);
  
  s[0] = 0;
  for(i = 0; i < n; i++) s[i] = 1;
  for(i = 2; i < n; i++) {
    if(s[i] == 1) {
      for(j = i*i; j < n; j += i) {
        s[j] = 0;
      }
    }
  }
  
  printf("Prime numbers found:\r\n");
  
  for(i = 0; i < n; i++) {
    if(s[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("End of the list.\r\n");
}

int main() {
  int i, n = 10;
  unsigned int a = 2024;
  char *pline;
  
  sieve(2000);
  
  printf("n = %d\r\n", n);
  for(i = 0; i < n; i++) {
    printf("i = %d, a = %d\r\n", i, a);
    a = a / 5;
  }
  for(i = 1; i < 200; i+=5) {
    LINE(1,i, 200, 200-i);
  }
  printf("Enter something: ");
  pline = readline();
  printf("\n");
  printf("You entered: %s\r\n", pline);
  primes(100);
  printf("Finished\r\n");
  return 0;
}

