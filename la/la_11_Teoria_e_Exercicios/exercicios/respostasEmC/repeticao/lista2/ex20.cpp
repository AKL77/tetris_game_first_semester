#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   int numero, aux, i;
   printf("Informe um numero:\n");
   scanf("%d", &numero);
   i = 2;
   while(i <= numero){
      bool ehPrimo = true;
      aux = i - 1;
      while(aux > 1)
         if (i % aux-- == 0)
            ehPrimo = false;
      if (ehPrimo && numero % i == 0){
         printf("%d ", i);
         numero = numero / i;
      } else
         i++;
   }
   printf("\n");
   system("PAUSE");
}
