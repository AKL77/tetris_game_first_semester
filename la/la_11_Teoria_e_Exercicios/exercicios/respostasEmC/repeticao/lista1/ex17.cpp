#include <stdio.h>
#include <stdlib.h>

int main(){
   int valor, fibs = 0, f1, f2, fib;
   do{
      printf("Digite um valor (negativo para encerrar):");
      scanf("%d", &valor);
      bool ehFib = false;
      if (valor >= 0){
         f1 = 0;
         f2 = 1;
         do {
            fib = f1 + f2;
            if (valor == 0 || valor == fib)
               ehFib = true; 
            f1 = f2;
            f2 = fib; 
         } while (fib < valor);
         if (ehFib)
            fibs++;
      }
   } while (valor >= 0);
   printf("O numero de valores lidos que sao da serie eh %d\n", fibs);
   system("PAUSE");
}
