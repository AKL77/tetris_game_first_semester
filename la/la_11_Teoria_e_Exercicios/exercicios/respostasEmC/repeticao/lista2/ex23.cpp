#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   int numero, aux;
   printf("Informe um numero:\n");
   scanf("%d", &numero);
   bool ehPrimo = false;
   while (!ehPrimo){
      numero++;
      ehPrimo = true;
      aux = numero - 1;
      while(aux > 1)
         if (numero % aux-- == 0)
            ehPrimo = false;         
   }
   printf("O numero %d eh o proximo primo\n", numero);
   system("PAUSE");
}
