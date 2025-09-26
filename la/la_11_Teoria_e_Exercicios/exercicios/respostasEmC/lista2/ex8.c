/* Programa Ex8 */

#include <stdio.h>
#include <stdlib.h>

int main(){
   int h1, m1, s1, h2, m2, s2, totalSegundos; 
   printf("Digite o valor de h1: ");
   scanf("%d", &h1);
   printf("Digite o valor de m1: ");
   scanf("%d", &m1);
   printf("Digite o valor de s1: ");
   scanf("%d", &s1);
   printf("Digite o valor de h2: ");
   scanf("%d", &h2);
   printf("Digite o valor de m2: ");
   scanf("%d", &m2);
   printf("Digite o valor de s2: ");
   scanf("%d", &s2);
   totalSegundos = (h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1);
   printf("O valor de totalSegundos eh %d\n", totalSegundos);
   system("PAUSE");
}
