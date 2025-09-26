/* Programa Ex9 */

#include <stdio.h>
#include <stdlib.h>

int main(){
   int a, b, c; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   printf("Digite o valor de c: ");
   scanf("%d", &c);
   float media; 
   media = (a + b + c) / 3.0;
   printf("O valor de media eh %f\n", media);
   system("PAUSE");
}
