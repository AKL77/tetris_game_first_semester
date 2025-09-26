/* Programa Ex6 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   int a, b, c, maiorAB, maiorABC; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   printf("Digite o valor de c: ");
   scanf("%d", &c);
   maiorAB = ((a + b) + abs(a - b)) / 2;
   maiorABC = ((maiorAB + c) + abs(maiorAB - c)) / 2;
   printf("O valor de maiorABC eh %d\n", maiorABC);
   int d, menorAB, menorABC, menorABCD; 
   printf("Digite o valor de d: ");
   scanf("%d", &d);
   menorAB = ((a + b) - abs(a - b)) / 2;
   menorABC = ((menorAB + c) - abs(menorAB - c)) / 2;
   menorABCD = ((menorABC + d) - abs(menorABC - d)) / 2;
   printf("O valor de menorABCD eh %d\n", menorABCD);
   system("PAUSE");
}
