/* Ex2 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   float a, volume, area; 
   printf("Digite o valor de a: ");
   scanf("%f", &a);
   area = 6 * pow(a, 2);
   volume = pow(a, 3);
   printf("O valor de area eh %f\n", area);
   printf("O valor de volume eh %f\n", volume);
   system("PAUSE");
}
