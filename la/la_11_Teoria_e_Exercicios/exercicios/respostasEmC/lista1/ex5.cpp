/* Programa Ex5 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   int numero, potencia, resultado; 
   printf("Digite o valor de numero: ");
   scanf("%d", &numero);
   printf("Digite o valor de potencia: ");
   scanf("%d", &potencia);
   resultado = pow(numero, potencia);
   printf("O valor de resultado eh %d\n", resultado);
   system("PAUSE");
}
