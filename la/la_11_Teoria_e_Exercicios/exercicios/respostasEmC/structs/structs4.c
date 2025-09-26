#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char sexo;
   int idade;
   int livrosLidos;
} Entrevistado;

main(){
   Entrevistado e[10];
   int i = -1;
   do {
      i++;
      fflush(stdin);
      printf("Sexo: ");
      scanf("%c", &e[i].sexo);
      printf("Idade: ");
      scanf("%d", &e[i].idade);
      if (e[i].idade > 0){
         printf("Livros lidos: ");
         scanf("%d", &e[i].livrosLidos);             
      }
   } while (e[i].idade > 0);
   int j;
   
   int totalLidosPorMenores10Anos = 0;
   for (j = 0; j < i; j++)
      if (e[j].idade < 10)
         totalLidosPorMenores10Anos += e[j].livrosLidos;
   
   int mulheresLeram5OuMaisLivros = 0;
   for (j = 0; j < i; j++)
      if (e[j].livrosLidos >= 5)
         mulheresLeram5OuMaisLivros++;
   
   float mediaIdadeLeramMenos5Livros = 0;
   int countLeramMenos5 = 0;
   for (j = 0; j < i; j++)
      if (e[j].livrosLidos < 5){
         mediaIdadeLeramMenos5Livros += e[j].idade;
         countLeramMenos5++;
      }
   mediaIdadeLeramMenos5Livros = mediaIdadeLeramMenos5Livros / countLeramMenos5;
   
   int naoLeramLivros = 0;
   for (j = 0; j < i; j++)
      if (e[j].livrosLidos == 0)
         naoLeramLivros++;
   float percentual = (float) naoLeramLivros / i * 100;
   
   
   for (j = 0; j < i; j++){
      printf("Sexo: %c, Idade: %d, Lidos: %d\n", e[j].sexo, 
         e[j].idade, e[j].livrosLidos);    
   }
   printf("Total de livros lidos por menores de 10 anos: %d\n", totalLidosPorMenores10Anos);
   printf("Quantidade de mulheres que leram 5 ou mais livros: %d\n", mulheresLeram5OuMaisLivros);
   printf("Media de idade de quem leu menos de 5 livros: %.2f\n", mediaIdadeLeramMenos5Livros);
   printf("Percentual de pessoas que nao leram livros: %.2f\n", percentual);
   system("pause");
}
