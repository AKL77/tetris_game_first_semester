#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, j, nota, media;
   for (i = 1; i <= 20; i++){
      media = 0;
      for (j = 1; j <= 3; j++){
         printf("Informe a %d nota: ", j);
         scanf("%d", &nota);       
         media += nota;
      }
      printf("A media do %do aluno eh %f\n", i, media / 3.0);
   }
   system("PAUSE");
}
