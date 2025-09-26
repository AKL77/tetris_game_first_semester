/* Ex2 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i % 2 == 0)
      printf("I eh um numero par = %d\n", i);
   else 
      printf("I eh um numero impar = %d\n", i);
   system("PAUSE");
}
