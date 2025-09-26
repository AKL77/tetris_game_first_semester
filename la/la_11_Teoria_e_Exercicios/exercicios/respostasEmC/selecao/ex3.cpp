/* Ex3 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i > 0)
      printf("O inverso de i eh =  %f", (1.0 / i));
   else 
      printf("O valor absoluto de i eh =  %d", (-1 * i));
   system("PAUSE");
}
