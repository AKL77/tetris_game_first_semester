/* Ex12 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int a, b; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   if (a == b)
      printf("a e b sao iguais\n");
   else 
      if (a > b)
         printf("a eh maior que b\n");
      else 
         printf("b eh maior que a\n");
   system("PAUSE");
}
