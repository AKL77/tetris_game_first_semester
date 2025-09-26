/* Ex15 */
#include <stdio.h>
#include <stdlib.h>

int main(){
   int a, b, c; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   printf("Digite o valor de c: ");
   scanf("%d", &c);
   if (a + b > c && b + c > a && a + c > b){
      if (a == b && b == c)
         printf("Eh um triangulo equilatero\n");
      else 
         if (a != c && a != b && b != c)
            printf("Eh um triangulo escaleno\n");
         else 
            printf("Eh um triangulo isosceles\n");
   }
   else 
      printf("Nao pode ser um triangulo\n");
   system("PAUSE");
}
