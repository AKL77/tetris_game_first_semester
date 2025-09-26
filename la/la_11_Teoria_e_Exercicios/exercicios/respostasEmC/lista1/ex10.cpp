/* Programa Ex10 */

#include <stdio.h>
#include <stdlib.h>

int main(){
   float valor, percentual; 
   printf("Digite o valor de valor: ");
   scanf("%f", &valor);
   printf("Digite o valor de percentual: ");
   scanf("%f", &percentual);
   float novoValor; 
   novoValor = valor * (percentual / 100 + 1);
   printf("O valor de novoValor eh %f\n", novoValor);
   system("PAUSE");
}
