#include <stdio.h>
#include <stdlib.h>

struct Produto{
   int codigo;
   float preco;     
};

struct Compra{
   int codigo;
   float quantidade;     
};

int main(){
   int qtdProdutos = 5;
   Produto catalogo[qtdProdutos];
   for(int i = 0; i < qtdProdutos; i++){
      printf("\nDigite o codigo do produto %d: ", i + 1);
      scanf("%d", &catalogo[i].codigo);
      printf("\nDigite o preco do produto %d: ", i + 1);
      scanf("%f", &catalogo[i].preco);
   }
   
   int qtdComprados = 3;
   Compra comprados[qtdComprados];
   for(int i = 0; i < qtdComprados; i++){
      bool achou;
      do{
         achou = false;
         printf("\nDigite o codigo do produto comprado %d: ", i + 1);
         scanf("%d", &comprados[i].codigo);
         for(int j = 0; j < qtdProdutos; j++)
            if (comprados[i].codigo == catalogo[j].codigo)
               achou = true;
         if (!achou)
            printf("\nCodigo Invalido!");
      } while(!achou);
      printf("\nDigite a quantidade do produto comprado %d: ", i + 1);
      scanf("%f", &comprados[i].quantidade);
   }
   
   printf("\nProdutos no Catalogo");
   for(int i = 0; i < qtdProdutos; i++)
      printf("\n[%d, %f]", catalogo[i].codigo, catalogo[i].preco);
   
   printf("\nProdutos Comprados");
   for(int i = 0; i < qtdComprados; i++)
      printf("\n[%d, %f]", comprados[i].codigo, comprados[i].quantidade);
   
   float total = 0;
   for(int i = 0; i < qtdComprados; i++)
      for(int j = 0; j < qtdProdutos; j++)
         if (comprados[i].codigo == catalogo[j].codigo)
            total += comprados[i].quantidade * catalogo[j].preco;
            
   printf("\nO total da compra eh %.2f", total);
   printf("\n");
   system("PAUSE");
}
