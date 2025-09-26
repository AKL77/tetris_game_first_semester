/* Ex6 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int a, b, soma; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   soma = a + b;
   if (soma > 20)
      soma = soma + 8;
   else
      soma = soma - 5;
   printf("O valor de soma eh %d\n", soma);
   system("PAUSE");
}
