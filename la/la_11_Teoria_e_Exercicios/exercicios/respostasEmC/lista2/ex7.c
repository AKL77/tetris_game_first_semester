/* Programa Ex7 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   int n, fibN; 
   float s; 
   printf("Digite o valor de n: ");
   scanf("%d", &n);
   s = (1 + pow(5, 1.0 / 2)) / 2;
   fibN = pow(s, n) / pow(5, 1.0 / 2) + 0.5;
   printf("O valor de fibN eh %d\n", fibN);
   system("PAUSE");
}
