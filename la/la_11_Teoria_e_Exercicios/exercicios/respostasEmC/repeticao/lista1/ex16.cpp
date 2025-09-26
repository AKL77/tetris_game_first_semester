#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, j, nota, faltas, aprovados, reprovados, a, b, c;
   aprovados = reprovados = a = b = c = 0;
   float media;
   for (i = 1; i <= 90; i++){
      media = 0.0;
      faltas = 0;
      for (j = 1; j <= 3; j++){
         printf("Informe a %da nota: ", j);
         scanf("%d", &nota);       
         media += nota;
      }
      printf("Informe o numero de faltas: ");
      scanf("%d", &faltas);       
      media = media / 3;
      printf("A media do %do aluno eh %f\n", i, media);
      if (media < 5.0 || faltas > 20 || (faltas > 10 && media < 7.0))
         reprovados++;
      else{
         aprovados++;
         if (media >= 9.0)
            a++;
         else      
            if (media >= 7.5)
               b++;
            else
               c++;
      }
   }
   printf("Percentual de aprovados: %f\%", (float) aprovados / 90 * 100);
   if (a >= b && a >= c)
      printf("O conceito maior eh A\n");
   else
      if (b >=a && b >= c)
         printf("O conceito maior eh B\n");
      else
         printf("O conceito maior eh C\n");

   system("PAUSE");
}
