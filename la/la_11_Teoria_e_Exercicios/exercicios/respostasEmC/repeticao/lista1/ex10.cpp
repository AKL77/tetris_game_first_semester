#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, numero = 0, fatorial = 1;
   int n;
   printf("Informe um numero: ");
   scanf("%d", &n);
   if (n != 0){
      while (fatorial <= n){
         for (fatorial = 1, i = 1; i <= numero; i++)
            fatorial *= i;
         if (fatorial <= n)
            numero++;
      }
   }
   printf("O menor numero cujo fatorial eh maior que %d eh: %d\n", n, numero);
   system("PAUSE");
}
