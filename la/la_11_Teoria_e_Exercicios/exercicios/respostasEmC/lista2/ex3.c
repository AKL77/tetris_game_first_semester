/* Ex3 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   float n1, n2, n3, media; 
   printf("Digite o valor de n1: ");
   scanf("%f", &n1);
   printf("Digite o valor de n2: ");
   scanf("%f", &n2);
   printf("Digite o valor de n3: ");
   scanf("%f", &n3);
   media = 6 / (1.0 / n1 + 2.0 / n2 + 3.0 / n3);
   printf("O valor de media eh %f\n", media);
   system("PAUSE");
}
