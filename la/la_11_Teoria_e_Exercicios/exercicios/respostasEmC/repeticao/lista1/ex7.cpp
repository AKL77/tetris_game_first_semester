#include <stdio.h>
#include <stdlib.h>

int main(){
   int numero;
   int c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
   c0 = c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = 0;
   printf("Digite o numero cujos algarismos serao ordenados:");
   scanf("%d", &numero);
   if (numero < 0)
      printf("O numero deve ser positivo");
   else{
      while (numero > 0){
         int resto = numero % 10;
         numero = numero / 10;
         switch (resto){
            case 0: c0++; break;       
            case 1: c1++; break;       
            case 2: c2++; break;       
            case 3: c3++; break;       
            case 4: c4++; break;       
            case 5: c5++; break;       
            case 6: c6++; break;       
            case 7: c7++; break;       
            case 8: c8++; break;       
            case 9: c9++; break;       
         }
      }
      int i;
      printf("O numero ordenado eh: ");   
      for (i = 0; i < c0; i++)
         printf("0");
      for (i = 0; i < c1; i++)
         printf("1");
      for (i = 0; i < c2; i++)
         printf("2");
      for (i = 0; i < c3; i++)
         printf("3");
      for (i = 0; i < c4; i++)
         printf("4");
      for (i = 0; i < c5; i++)
         printf("5");
      for (i = 0; i < c6; i++)
         printf("6");
      for (i = 0; i < c7; i++)
         printf("7");
      for (i = 0; i < c8; i++)
         printf("8");
      for (i = 0; i < c9; i++)
         printf("9");
   }
   printf("\n");        
   system("PAUSE");
}

