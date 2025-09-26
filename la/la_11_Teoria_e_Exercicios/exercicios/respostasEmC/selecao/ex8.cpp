/* Ex8 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i % 3 == 0)
      printf("I eh multiplo de 3: %d\n", i);
   else 
      printf("I nao eh multiplo de 3: %d\n", i);
   system("PAUSE");
}
