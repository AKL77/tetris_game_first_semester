#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   int numero, aux;
   bool ehPrimo = true;
   printf("Informe um numero:\n");
   scanf("%d", &numero);
   aux = numero - 1;
   while(aux > 1)
      if (numero % aux-- == 0)
         ehPrimo = false;
   printf("O numero %d %seh primo\n", numero, ehPrimo ? "": "nao ");
   system("PAUSE");
}
