#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   int menor, somaDivisores, divisorAtual, numero, contNrPerfeitos = 0;
   do {
      printf("Digite um numero: ");
      scanf("%d", &numero);
      somaDivisores = 1;
      divisorAtual = 2;
      do{
         if (numero % divisorAtual == 0)
            somaDivisores += divisorAtual;
         divisorAtual++;
      } while (divisorAtual <= numero / 2);
      if (numero == somaDivisores){
         contNrPerfeitos++;
         if (contNrPerfeitos == 1 || numero < menor)
            menor = numero;
      }
   } while (contNrPerfeitos < 10);
   printf("O menor eh %d\n", menor);
   system("PAUSE");
}
