/* Ex10 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   float salario, valor; 
   printf("Digite o valor de salario: ");
   scanf("%f", &salario);
   printf("Digite o valor de valor: ");
   scanf("%f", &valor);
   if (valor > salario * 0.3)
      printf("O emprestimo nao pode ser concedido %f\n", valor);
   else 
      printf("O emprestimo pode ser concedido %f\n", valor);
   system("PAUSE");
}
