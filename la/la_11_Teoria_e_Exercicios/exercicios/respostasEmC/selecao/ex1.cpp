/* Ex1 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i > 20){
      printf("A metade eh %f", (i / 2.0));
   }
   system("PAUSE");
}
