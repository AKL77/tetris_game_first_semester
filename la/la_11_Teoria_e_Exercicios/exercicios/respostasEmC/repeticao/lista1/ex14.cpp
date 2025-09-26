#include <stdio.h>
#include <stdlib.h>

int main(){
   int valor, positivos = 0, negativos = 0;
   float media = 0.0;
   do{
      printf("Digite um valor (zero para encerrar):");
      scanf("%d", &valor);
      if (valor != 0)
         if (valor > 0){
            media += valor;
            positivos++;              
         } else
            negativos++;
   } while (valor != 0);
   if (positivos + negativos > 0){
      printf("Media dos positivos lidos: %f\n", media / positivos);
      printf("Numeros negativos lidos: %d\n", negativos);             
   }
   else
      printf("Nao foi lido numero algum\n");
   system("PAUSE");
}
