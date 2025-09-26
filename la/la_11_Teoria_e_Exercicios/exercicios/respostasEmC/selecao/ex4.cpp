/* Ex4 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i == 0)
      printf("I eh nulo\n");
   else 
      if (i > 0)
         printf("I eh positivo\n");
      else 
         printf("I eh negativo\n");
   system("PAUSE");
}
