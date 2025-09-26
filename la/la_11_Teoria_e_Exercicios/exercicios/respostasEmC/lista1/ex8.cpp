/* Programa Ex8 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   printf("Perimetro do Triangulo\n");
   int a, b, c; 
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   printf("Digite o valor de c: ");
   scanf("%d", &c);
   int pTriangulo; 
   pTriangulo = a + b + c;
   printf("O valor de pTriangulo eh %d\n", pTriangulo);
   printf("Perimetro do Triangulo Retangulo\n");
   printf("Digite o valor de a: ");
   scanf("%d", &a);
   printf("Digite o valor de b: ");
   scanf("%d", &b);
   float pTR; 
   pTR = pow((pow(a, 2) + pow(b, 2)), 1.0 / 2);
   printf("O valor de pTR eh %f\n", pTR);
   printf("Perimetro do Quadrado\n");
   int lado, pLado; 
   printf("Digite o valor de lado: ");
   scanf("%d", &lado);
   pLado = 4 * lado;
   printf("O valor de pLado eh %d\n", pLado);
   printf("Perimetro do Retangulo\n");
   int base, altura, pRetangulo; 
   printf("Digite o valor de base: ");
   scanf("%d", &base);
   printf("Digite o valor de altura: ");
   scanf("%d", &altura);
   pRetangulo = 2 * base + 2 * altura;
   printf("O valor de pRetangulo eh %d\n", pRetangulo);
   printf("Perimetro do Circulo\n");
   int raio; 
   printf("Digite o valor de raio: ");
   scanf("%d", &raio);
   float pCirculo; 
   pCirculo = 2 * 3.14159 * raio;
   printf("O valor de pCirculo eh %f\n", pCirculo);
   system("PAUSE");
}
