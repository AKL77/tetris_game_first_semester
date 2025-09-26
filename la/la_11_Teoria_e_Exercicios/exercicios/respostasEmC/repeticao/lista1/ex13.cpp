#include <stdio.h>
#include <stdlib.h>

int main(){
   int valor, maior, segundoMaior;
   bool primeiroLido = false;
   bool segundoLido = false;
   do{
      printf("Digite um valor (zero para encerrar):");
      scanf("%d", &valor);
      if (valor != 0){
         if (!primeiroLido){
            maior = valor;
            primeiroLido = true;                   
         } else {
            if (!segundoLido){
               segundoLido = true;
               if (valor > maior){
                  segundoMaior = maior;                  
                  maior = valor;
               } else 
                  segundoMaior = valor;
            } else {
               if (valor > segundoMaior){
                  segundoMaior = valor;
                  if (segundoMaior > maior){
                     int aux = segundoMaior;
                     segundoMaior = maior;
                     maior = aux;
                  }
               }       
            }       
         }
      }
   } while (valor != 0);
   if (!primeiroLido) 
      printf("Nenhum numero foi lido\n");
   else
      if (!segundoLido)
         printf("O maior numero eh %d. Nao foi lido um 2o numero\n", maior);
      else
         printf("O maior numero eh %d. O 2o maior eh %d\n", maior, segundoMaior);
   system("PAUSE");
}
