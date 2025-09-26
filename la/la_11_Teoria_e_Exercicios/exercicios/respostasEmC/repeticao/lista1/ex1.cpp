#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, numero;
   for (i = 0; i < 10; i++){
      printf("Digite um numero: ");
      scanf("%d", &numero);
      printf("O quadrado deste numero eh: %d\n", numero * numero);
   }    
   system("PAUSE");
}
