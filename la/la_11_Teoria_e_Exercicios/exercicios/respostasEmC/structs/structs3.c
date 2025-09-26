#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
   int matricula;
   char nome[50];
   float salario;
} Funcionario;

main(){
   Funcionario f[MAX];
   int nr;
   int i = 0;
   printf("\n------------------------------------------------\n");
   printf("Cadastro de Funcionarios\n");
   printf("------------------------------------------------\n");
   do{
       printf("Informe o nr de funcionarios a serem lidos (maximo %d): ", MAX);
       scanf("%d", &nr);        
       if (nr > MAX || nr < 0)
          printf("Valor invalido. Deve ser no intervalo (0, %d).\n", MAX);
   } while (nr > MAX || nr < 0);
   for (i = 0; i < nr; i++){
      printf("Matricula: ");
      scanf("%d", &f[i].matricula);
      fflush(stdin);
      printf("Nome: ");
      gets(f[i].nome);
      printf("Salario: ");
      scanf("%f", &f[i].salario);       
   }
   float somaSalarios = 0;
   for (i = 0; i < nr; i++)
      somaSalarios += f[i].salario;
   
   float salarioMedio = 0;
   if (nr != 0)
      salarioMedio = somaSalarios / nr;
   
   float maiorSalario;
   if (nr != 0)
      maiorSalario = f[0].salario;
      
   int codigoMaiorSalario = 0;
   for (i = 1; i < nr; i++)
      if (f[i].salario > maiorSalario){
         maiorSalario = f[i].salario;
         codigoMaiorSalario = i;      
      }

   printf("\n------------------------------------------------\n");
   printf("Relatorio\n");
   printf("------------------------------------------------\n");
   for (i = 0; i < nr; i++){
      printf("Matricula: %d, Nome: %s, Salario: %.2f\n", f[i].matricula, 
         f[i].nome, f[i].salario);
   }
   if (nr > 0){
      printf("Soma dos salarios: %.2f\n", somaSalarios);
      printf("Salario medio: %.2f\n", salarioMedio);
      printf("Maior salario: %.2f\n", maiorSalario);
      printf("Funcionario com maior salario: %d - %s\n", f[codigoMaiorSalario].matricula, 
         f[codigoMaiorSalario].nome); 
   } else
      printf("Nao ha funcionarios cadastrados.\n");
   printf("------------------------------------------------\n");
   system("pause");
}
