/* Programa Ex6 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   int a, b, c; 
   float rdelta; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   printf("Digite o valor de c: ");
   scanf("%d", &c);
   rdelta = pow((b * b - 4 * a * c), 1.0 / 2);
   float r1, r2; 
   r1 = (-b + rdelta) / (2 * a);
   r2 = (-b - rdelta) / (2 * a);
   printf("O valor de r1 eh %f\n", r1);
   printf("O valor de r2 eh %f\n", r2);
   system("PAUSE");
}
