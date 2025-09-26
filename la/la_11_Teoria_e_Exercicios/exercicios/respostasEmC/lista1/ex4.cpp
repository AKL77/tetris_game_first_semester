/* Programa Ex4 */

#include <stdio.h>
#include <stdlib.h>

int main(){
   int a, b, soma, subtracao, multiplicacao, divisao; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   soma = a + b;
   subtracao = a - b;
   multiplicacao = a * b;
   divisao = a / b;
   printf("O valor de soma eh %d\n", soma);
   printf("O valor de subtracao eh %d\n", subtracao);
   printf("O valor de multiplicacao eh %d\n", multiplicacao);
   printf("O valor de divisao eh %d\n", divisao);
   system("PAUSE");
}
