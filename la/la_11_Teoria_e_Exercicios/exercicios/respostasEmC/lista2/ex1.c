/* Programa Ex1 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   float a, b, c; 
   printf("Digite o valor de a: ");
   scanf("%f", &a);
   printf("Digite o valor de b: ");
   scanf("%f", &b);
   printf("Digite o valor de c: ");
   scanf("%f", &c);
   float semi; 
   semi = (a + b + c) / 2.0;
   float area; 
   area = pow((semi * (semi - a) * (semi - b) * (semi - c)), 1.0 / 2);
   printf("O valor de area eh %f\n", area);
   system("PAUSE");
}
