#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, numero, anterior;
   bool crescente = true;
   bool decrescente = true;
   bool todosIguais = true;
   bool foraOrdem;
   for (i = 0; i < 10; i++){
      printf("Digite um numero: ");
      scanf("%d", &numero);
      if (i == 0)
         anterior = numero;
      else {
         if (numero > anterior){
            todosIguais = false;
            decrescente = false;
         } else
            if (numero < anterior){
               todosIguais = false;
               crescente = false;
            } 
         anterior = numero;  
      } 
   }    
   foraOrdem = !(crescente || decrescente);
   if (foraOrdem)
      printf("Fora de ordem\n");
   else 
      if (todosIguais)
         printf("Todos iguais\n");
      else
         if (crescente)
            printf("Numeros em ordem crescente\n");
         else 
            printf("Numeros em ordem decrescente\n");
   system("PAUSE");
}
