#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int f, num, r = 1;
    printf("Digite quantos numeros calcular:\n");
    scanf("%d", &f);
    for(; f != 0; r++)
       for (num = 1; num < rodada && f !=0; num++, f--);
    printf("O valor solicitado eh %d/%d\n", num - 1, r - num);
    system("PAUSE");
}
