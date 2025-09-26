#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, nota, maior;
   for (i = 1; i <= 30; i++){
      printf("Digite a nota do %do aluno: ", i);
      scanf("%d", &nota);
      if (i == 1 || nota > maior)
         maior = nota;
   }    
   printf("A maior nota eh %d", maior);
   system("PAUSE");
}
