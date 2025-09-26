#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, numero, menor, contagem;
   for (i = 0; i < 200; i++){
      printf("Digite um numero: ");
      scanf("%d", &numero);
      if (i != 0 && numero == menor)
         contagem++;
      if (i == 0 || numero < menor){
         menor = numero;          
         contagem = 1;  
      }
   }    
   printf("O numero de valores iguais ao menor valor eh %d", contagem);
   system("PAUSE");
}
