/* Ex13 */
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
   if (a <= b && a <= c){
      if (b <= c)
         printf("A ordem eh a, b e c: %d %d %d", a, b, c);
      else 
         printf("A ordem eh a, c e b: %d %d %d", a, c, b);
   }
   else {
      if (b <= a && b <= c){
         if (a <= c)
            printf("A ordem eh b, a e c: %d %d %d", b, a, c);
         else 
            printf("A ordem eh b, c e a: %d %d %d", b, c, a);
      }
      else {
         if (a <= b)
            printf("A ordem eh c, a e b: %d %d %d", c, a, b);
         else 
            printf("A ordem eh c, b e a: %d %d %d", c, b, a);
      }
   }
   system("PAUSE");
}
