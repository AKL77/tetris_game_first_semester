#include <stdio.h>
#include <stdlib.h>

int main(){
   int valor;
   bool imparLido = false;
   int menorImpar;
   do{
      printf("Digite um valor (negativo para encerrar):");
      scanf("%d", &valor);
      if (valor >= 0 && valor % 2 == 1)
         if (imparLido == false){ // Se esse fosse o primeiro impar lido
            printf("Acabei de ler um impar, o primeiro deles\n");
            menorImpar = valor; // Assumo que o menor Impar eh o numero lido
            imparLido = true; // Jah li um impar
         } else{
            printf("Do segundo impar em diante...\n");         
            if (valor < menorImpar) 
               menorImpar = valor;      
         }
  } while (valor >= 0);
   if (imparLido == true)
      printf("O menor impar lido eh: %d ", menorImpar);
   else
      printf("Nao foram lidos numeros impares\n");
   
   system("PAUSE");
}
