#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 200

typedef struct {
   int serie;
   int livrosMes;
   bool gostaRedacao;
} Aluno;

main(){
   Aluno a[MAX]; 
   int i = 0;
   do{
      printf("Digite a serie (1-4): ");
      scanf("%d", &a[i].serie);
      if (a[i].serie == 0)
         break;
      printf("Nr de livros lidos: ");
      scanf("%d", &a[i].livrosMes);
      char gostaRedacao;
      fflush(stdin);
      printf("Gosta de redacao (S-N): ");
      scanf("%c", &gostaRedacao);
      a[i].gostaRedacao = gostaRedacao == 's' || gostaRedacao == 'S'; 
      i++;
   } while (true);
   int j = 0;

   int nrAlunosNa3aSerie = 0;
   int nrAlunosNa3aSerieNaoGostamRedacao = 0;
   int maiorNrLivrosAluno4aSerie = -1;
   float percentualAlunos3aSerieNaoGostamRedacao = 0.0;
   for (j = 0; j < i; j++)
      if (a[j].serie == 3){
         nrAlunosNa3aSerie++;
         if (!a[j].gostaRedacao)
            nrAlunosNa3aSerieNaoGostamRedacao++;
      }
      else
         if (a[j].serie == 4)
            if (a[j].livrosMes > maiorNrLivrosAluno4aSerie)
               maiorNrLivrosAluno4aSerie = a[j].livrosMes;
   if (nrAlunosNa3aSerie != 0)
      percentualAlunos3aSerieNaoGostamRedacao = 
         ((float) nrAlunosNa3aSerieNaoGostamRedacao / nrAlunosNa3aSerie) * 100;
   
   printf("\nAlunos na 3a serie: %d.", nrAlunosNa3aSerie);
   if (maiorNrLivrosAluno4aSerie != -1)
      printf("\nMais livros lidos na 4a serie: %d.", maiorNrLivrosAluno4aSerie);
   else
      printf("\nNao ha ninguem da 4a serie.");
   if (nrAlunosNa3aSerie != 0)
      printf("\nPercentual que nao gosta de redacao na 3a serie: %.2f.\n", percentualAlunos3aSerieNaoGostamRedacao);
   else
      printf("\nNao ha ninguem da 3a serie.\n");   
   system("pause");
}
