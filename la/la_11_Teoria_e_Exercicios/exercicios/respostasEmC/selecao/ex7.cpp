/* Ex7 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   int i; 
   printf("Digite o valor de i: ");
   scanf("%d", &i);
   if (i >= 0)
      printf("Raiz de i: %f", (pow(i, 1.0 / 2)));
   else 
      printf("Quadrado de i: %f", (pow(i, 2)));
   system("PAUSE");
}
