/* Ex9 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i % 10 == 0)
      printf("I eh divisivel por 10, por 2 e por 5\n");
   else {
      if (i % 5 == 0)
         printf("I eh divisivel por 5\n");
      else
         if (i % 2 == 0)
            printf("I eh divisivel por 2\n");
   }
   system("PAUSE");
}
