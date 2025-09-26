#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct {
   int id;
   int idade;
   int nota;
} Espectador;

main(){
   Espectador e[MAX]; 
   int i;
   for (i = 0; i < MAX; i++){
      e[i].id = i + 1;
      printf("Idade: ");
      scanf("%d", &e[i].idade);
      printf("Nota: ");
      scanf("%d", &e[i].nota);       
   }
   // Calcular
   int notas10 = 0, notas5OuMenos = 0;
   float mediaIdade = 0;
   float idMaisVelha = e[0].id;
   float idadeMaisVelha = e[0].idade;
   for (i = 0; i < MAX; i++){
      if (e[i].nota == 10)
         notas10++;
      if (e[i].nota <=5)
         notas5OuMenos++;
      if (e[i].idade > idadeMaisVelha){
         idadeMaisVelha = e[i].idade;
         idMaisVelha = e[i].id;                     
      }
      mediaIdade += e[i].idade;
   }
   mediaIdade /= MAX;
   float percentualNotas5OuMenos = ((float) notas5OuMenos / MAX) * 100;
   // Mostrar
   printf("Quantidade de notas 10: %d\n", notas10);
   printf("Media de idade de quem respondeu: %.2f\n", mediaIdade);
   printf("Percentual de notas 5 ou menos: %.2f\n", percentualNotas5OuMenos);
   printf("ID da pessoa mais velha: %.2f\n", percentualNotas5OuMenos);
   system("pause");
}
