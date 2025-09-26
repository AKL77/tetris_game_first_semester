#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, j, nota, qtdAlunos;
   float media;
   printf("Digite a quantidade de alunos:");
   scanf("%d", &qtdAlunos);
   for (i = 1; i <= qtdAlunos; i++){
      media = 0.0;
      for (j = 1; j <= 3; j++){
         printf("Informe a %da nota: ", j);
         scanf("%d", &nota);       
         media += 1.0 / nota;
      }
      media = 3.0 / media;
      printf("A media do %do aluno eh %f\n", i, media);
      printf("%s\n", media >= 6.0 ? "Aprovado" : "Reprovado");
   }
   system("PAUSE");
}
