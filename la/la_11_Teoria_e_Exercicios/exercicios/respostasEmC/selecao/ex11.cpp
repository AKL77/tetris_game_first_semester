/* Ex11 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i > 999 || i < 100)
      printf("O numero informado nao tem algarismo da centena\n");
   else
      if (i / 100 % 2 == 0)
         printf("O algarismo das centenas eh par\n");
      else 
         printf("O algarismo das centenas eh impar\n");
   system("PAUSE");
}
