/* Programa Ex5 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   float valor, percentual, meses, saldo; 
   printf("Digite o valor de valor: ");
   scanf("%f", &valor);
   printf("Digite o valor de percentual: ");
   scanf("%f", &percentual);
   printf("Digite o valor de meses: ");
   scanf("%f", &meses);
   saldo = valor * pow((1.0 + percentual / 100.0), meses);
   printf("O valor de saldo eh %f\n", saldo);
   system("PAUSE");
}
