#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int rodada, numerador;
    int faltaCalcular;
    printf("Digite quantos numeros calcular:\n");
    scanf("%d", &faltaCalcular);
    rodada = 1;
    while(faltaCalcular != 0){
       numerador = 1;
       while (numerador < rodada && faltaCalcular !=0){
          if (faltaCalcular == 1)
             printf("O valor solicitado eh %d/%d\n", numerador, rodada - numerador);
          faltaCalcular = faltaCalcular - 1;
          numerador = numerador + 1;
       }
       rodada = rodada + 1;                  
    }
    system("PAUSE");
}
