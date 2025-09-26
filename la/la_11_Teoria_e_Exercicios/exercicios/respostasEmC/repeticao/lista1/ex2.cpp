#include <stdio.h>
#include <stdlib.h>

int main(){
   int nrInteiros, i;
   printf("Informe o numero de inteiros a serem mostrados: ");
   scanf("%d", &nrInteiros);
   for (i = 1; i <= nrInteiros; i++)
      printf("O %do numero inteiro eh: %d\n", i, i);
   system("PAUSE");
}
