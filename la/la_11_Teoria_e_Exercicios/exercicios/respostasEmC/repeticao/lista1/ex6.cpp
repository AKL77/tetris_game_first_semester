#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, valor, soma = 0, multiplicacao = 1, maior, menor;
   for (i = 1; i <= 40; i++){
      printf("Digite o %do valor: ", i);
      scanf("%d", &valor);
      if (i == 1 || valor > maior)
         maior = valor;
      if (i == 1 || valor < menor)
         menor = valor;
      soma += valor;
      multiplicacao *= valor;
   }    
   printf("A soma eh: %d\n", soma);
   printf("A multiplicacao eh: %d\n", multiplicacao);
   printf("O maior eh: %d\n", maior);
   printf("O menor eh: %d\n", menor);
   printf("A media eh: %f\n", soma / 40.0);
   system("PAUSE");
}

