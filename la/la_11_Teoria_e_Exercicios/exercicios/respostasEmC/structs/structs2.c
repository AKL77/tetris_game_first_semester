#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int codigo;
   int nrHorasTrabalhadas;
   int nrDependentes; 
   float salarioBruto;
   float salarioLiquido;
   float descontoINSS;
   float descontoIR;       
} Funcionario;

main(){
   Funcionario f[10];
   int i = 0;
   printf("****** Entrada ********\n");
   for (i = 0; i < 10; i++){
      printf("Funcionario #%d\n", i + 1);
      f[i].codigo = i + 1;
      printf("Nr hrs trabalhadas: ");
      scanf("%d", &f[i].nrHorasTrabalhadas);
      printf("Nr dependentes: ");
      scanf("%d", &f[i].nrDependentes);
   }
   printf("****** Calculo ********\n");
   for (i = 0; i < 10; i++){
       f[i].salarioBruto = 12 * f[i].nrHorasTrabalhadas;
       f[i].salarioBruto += 40 * f[i].nrDependentes;
       f[i].descontoINSS = f[i].salarioBruto * 0.085;
       f[i].descontoIR = f[i].salarioBruto * 0.05;
       f[i].salarioLiquido = f[i].salarioBruto - f[i].descontoINSS - f[i].descontoIR;
   }   
   printf("****** Saida ********\n");
   for (i = 0; i < 10; i++){
      printf("Funcionario #%d\n", i + 1);
      printf("----------------------------------------\n");
      printf("Salario Bruto: %.2f\n", f[i].salarioBruto);
      printf("Desconto INSS: %.2f\n", f[i].descontoINSS);
      printf("Desconto IR: %.2f\n", f[i].descontoIR);
      printf("Salario Liquido: %.2f\n", f[i].salarioLiquido);
      printf("----------------------------------------\n");
   }   
   system("pause");
}
