#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, numero, fatorial = 1;
   printf("Informe um numero:");
   scanf("%d", &numero);
   for (i = 1; i <= numero; i++)
      fatorial *= i;
   printf("O fatorial de %d eh: %d\n", numero, fatorial);
   system("PAUSE");
}
