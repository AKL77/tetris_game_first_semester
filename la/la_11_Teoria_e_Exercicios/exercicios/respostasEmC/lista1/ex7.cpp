/* Programa Ex7 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   printf("Area do Triangulo Retangulo\n");
   int base, altura; 
   printf("Digite o valor de base: ");
   scanf("%d", &base);
   printf("Digite o valor de altura: ");
   scanf("%d", &altura);
   int areaTR; 
   areaTR = (base * altura) / 2;
   printf("O valor de areaTR eh %d\n", areaTR);
   printf("Area do Quadrado\n");
   int lado; 
   printf("Digite o valor de lado: ");
   scanf("%d", &lado);
   int areaQ; 
   areaQ = lado * lado;
   printf("O valor de areaQ eh %d\n", areaQ);
   printf("Area do Retangulo\n");
   printf("Digite o valor de base: ");
   scanf("%d", &base);
   printf("Digite o valor de altura: ");
   scanf("%d", &altura);
   int areaR; 
   areaR = base * altura;
   printf("O valor de areaR eh %d\n", areaR);
   printf("Area do Losango\n");
   int dMaior, dMenor; 
   printf("Digite o valor de dMaior: ");
   scanf("%d", &dMaior);
   printf("Digite o valor de dMenor: ");
   scanf("%d", &dMenor);
   int areaL; 
   areaL = (dMaior * dMenor) / 2;
   printf("O valor de areaL eh %d\n", areaL);
   printf("Area do Trapezio\n");
   int bMaior, bMenor; 
   printf("Digite o valor de bMaior: ");
   scanf("%d", &bMaior);
   printf("Digite o valor de bMenor: ");
   scanf("%d", &bMenor);
   printf("Digite o valor de altura: ");
   scanf("%d", &altura);
   int areaTrap; 
   areaTrap = ((bMaior + bMenor) / 2) * altura;
   printf("O valor de areaTrap eh %d\n", areaTrap);
   printf("Area do Circulo\n");
   int raio; 
   printf("Digite o valor de raio: ");
   scanf("%d", &raio);
   float areaC; 
   areaC = 3.14159 * pow(raio, 2);
   printf("O valor de areaC eh %f\n", areaC);
   system("PAUSE");
}
