#include <stdio.h>
#include <stdlib.h>


#define TEN 10
#define TWENTY 20


int main(){
    int a, b, c;
    a = TEN;
    b = a + TWENTY;
    c = a * b;
    printf("c = %d\n", c);
    exit(0);
}