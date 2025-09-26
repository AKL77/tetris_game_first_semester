#include <stdio.h>
#include <stdlib.h>

int main(){
   int nrInteiros, i, soma = 0;
   printf("Informe o numero de inteiros a serem mostrados: ");
   scanf("%d", &nrInteiros);
   for (i = 1; i <= nrInteiros; i++)
      soma+= i;
   printf("A soma dos %d primeiros inteiros eh: %d\n", nrInteiros, soma);
   system("PAUSE");
}
