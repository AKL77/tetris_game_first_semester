#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Funcao 1
float volume(int raio){
   return 4/3 * M_PI * pow(raio, 3);
}

// Funcao 2
float media(int n1, int n2, int n3, char letra){
   if (letra == 'A')      
      return (float)(n1 + n2 + n3) / 3;
   if (letra == 'P')      
      return (float)(n1 * 5 + n2 * 3 + n3 * 2) / 10;
}

// Funcao 3
bool ehPrimo(int valor){
   int aux = valor - 1;
   while(aux > 1)
      if (valor % aux-- == 0)
         return false;
   return true;      
}

// Funcao 4
void imprimirRaizes(int a, int b, int c){
   float rdelta = pow((b * b - 4 * a * c), 1.0 / 2);
   float r1 = (-b + rdelta) / (2 * a);
   float r2 = (-b - rdelta) / (2 * a);
   printf("\nO valor de r1 eh %.2f", r1);
   printf("\nO valor de r2 eh %.2f", r2);        
}

// Funcao 5 - aproximada - precisariam ser considerados anos bissextos...
// ...meses com 28, 29, 30 e 31 dias
int idadeEmDias(int anos, int meses, int dias){
   return anos * 365 + meses * 30 + dias;
}
   
// Funcao 6
char* categoria(int idade){
   if (idade >= 18)
      return "Adulto";
   if (idade >= 14)
      return "Juvenil B";
   if (idade >= 11)
      return "Juvenil A";
   if (idade >= 8)
      return "Infantil B";
   if (idade >= 5)
      return "Infantil A";
   return "Sem categoria ainda";
}

// Funcao 7
bool negativo(int valor){
   return valor < 0;     
}


// Funcao 8
char conceito(float media){
   if (media >= 9)
      return 'A';
   if (media >= 7)
      return 'B';
   if (media >= 5)
      return 'C';
   return 'D';
}

// Funcao 9
int fatorial(int valor){
   int i, resultado = 1;
   for (i = 1; i <= valor; i++)
      resultado *= i;       
   return resultado;
}

// Funcao 10
float soma(int valor){
   int i; 
   float resultado = 1;
   for (i = 2; i <= valor; i++)      
      resultado += (float) 1 / i;
   return resultado;
}

int main(){
   int x = 10;
   printf("\nO volume de uma esfera de raio 10 eh: %.2f", volume(x)); 
   printf("\nA media aritmetica entre 10, 20 e 30 eh: %.2f", media(10, 20, 30, 'A')); 
   printf("\nA media ponderada entre 10, 20 e 30 eh: %.2f", media(10, 20, 30, 'P')); 
   printf("\nO numero 20 eh primo? %s", ehPrimo(20) ? "Sim" : "Nao"); 
   printf("\nO numero 23 eh primo? %s", ehPrimo(23) ? "Sim" : "Nao"); 
   imprimirRaizes(3, 5, 2);
   printf("\nA idade aproximada em dias de uma pessoa com 25 anos, 3 meses e 12 dias eh de %d dias", 
      idadeEmDias(25, 3, 12));
   printf("\nA categoria de um nadador de 12 anos eh: %s", categoria(12));
   printf("\nO valor -10 eh %s", negativo(-10) ? "negativo" : "positivo");
   printf("\nO valor 10 eh %s", negativo(10) ? "negativo" : "positivo");
   printf("\nO conceito de um aluno com nota 7,5 eh %c", conceito(7.5));
   printf("\nO fatorial de 5 eh %d", fatorial(5));
   printf("\nA soma passando 2 como parametro eh %.2f\n", soma(2));
   system("PAUSE");
}
