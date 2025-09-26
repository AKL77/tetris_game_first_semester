/* Programa Ex4 */

#include <stdio.h>
#include <stdlib.h>

int main(){
   float x1, x2, y1, y2, distancia; 
   printf("Digite o valor de x1: ");
   scanf("%f", &x1);
   printf("Digite o valor de x2: ");
   scanf("%f", &x2);
   printf("Digite o valor de y1: ");
   scanf("%f", &y1);
   printf("Digite o valor de y2: ");
   scanf("%f", &y2);
   distancia = pow((pow((x2 - x1), 2) + pow((y2 - y1), 2)), 1.0 / 2);
   printf("O valor de distancia eh %f\n", distancia);
   system("PAUSE");
}
