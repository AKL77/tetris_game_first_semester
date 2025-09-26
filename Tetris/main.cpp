#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#include "auxiliar.h"

// Implementei toda a parte básica + Game Over/Reset + Velocidade das peças aumentam com o passar do tempo + Projecao da Peça Caindo + Mostra a Proxima Peca + Funcao Hold
//As instruções para jogar o  jogo podem ser vistas pelo usuário ao clicar no botão options, que mostra o que cada tecla faz

void DrawMouseScreenCoords()
{
    char str[100];
    sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    CV::text(10,300, str);
    sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
    CV::text(10,320, str);
}

void render()
{
    CV::clear(0,0,0);

    ControleVelocidadePeca++;

    if(jogar == 1 && GameOver == 0)
    {
        DesenhaPeca();
        DesenhaTabuleiro();
    }
    else if(jogar == 0 && Options == 0)
        DesenhaMenu();
    else if(Options == 1)
        Manual();
    else if (GameOver == 1)
        FimDeJogo();
}

void keyboard(int key)
{
   printf("\nTecla: %d" , key);

   switch(key)
   {
      case 27:
        exit(0);
        break;

      case 32: // hard drop // space
        while(parar == 0)
            descePeca();
        parar = 0;
        break;

      case 99: // hold  // c
        if(PodeUsarHold == 1)
            hold();
        break;

      case 200: // esquerda // setinha pra esquerda
        MoveEsquerda();
        break;

      case 201: // girar // setinha pra cima
        giraPeca();
        break;

	  case 202: // direita // setinha direita
        MoveDireita();
        break;

	  case 203: // desce a peca // setinha pra baixo
        descePeca();
        break;
   }
}

void keyboardUp(int key)
{
   printf("\nLiberou tecla: %d" , key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

   mouseX = x;
   mouseY = y;

   if(state == 0) // controla os cliques nos botões
   {
        if(mouseX >= Botao[0].X1 && mouseX <= Botao[0].X2 && mouseY >= Botao[0].Y1 && mouseY <= Botao[0].Y2 && jogar == 0 && Options == 0)
            jogar = !jogar;
        if(mouseX >= Botao[1].X1 && mouseX <= Botao[1].X2 && mouseY >= Botao[1].Y1 && mouseY <= Botao[1].Y2 && jogar == 0 && Options == 0)
            Options = !Options;
        if(mouseX >= Botao[2].X1 && mouseX <= Botao[2].X2 && mouseY >= Botao[2].Y1 && mouseY <= Botao[2].Y2 && Options == 1)
            Options = !Options;
        if(mouseX >= Botao[3].X1 && mouseX <= Botao[3].X2 && mouseY >= Botao[3].Y1 && mouseY <= Botao[3].Y2 && GameOver == 1)
        {
            for(i = 0; i < LinhasBoard - FundoDoTabuleiro; i++) // as peças do tabuleiras são retiradas, ao zerar a matriz do tabuleiro
                for(j = 0; j < ColunasBoard; j++)
                    tabuleiro[i][j] = 0;
            for(i = 0; i < DimensoesPecas; i++) // a grade da peça armazenada é zerada para não imprimir nem guardar nada no hold na próxima partida
                for(j = 0; j < DimensoesPecas; j++)
                    PecaArmazenada.grade[i][j] = 0;
            VelocidadePeca = 50; // a velocidade da peça é resetada
            Score = 0; // o score é zerado
            Level = 0;
            PecaGuardada = 0; // essa flag é reiniciada
            GameOver = 0;
        }
        if(mouseX >= Botao[4].X1 && mouseX <= Botao[4].X2 && mouseY >= Botao[4].Y1 && mouseY <= Botao[4].Y2 && GameOver == 1)
        {
            for(i = 0; i < LinhasBoard - FundoDoTabuleiro; i++) // as peças do tabuleiras são retiradas, ao zerar a matriz do tabuleiro
                for(j = 0; j < ColunasBoard; j++)
                    tabuleiro[i][j] = 0;
            for(i = 0; i < DimensoesPecas; i++) // a grade da peça armazenada é zerada para não imprimir nem guardar nada no hold na próxima partida
                for(j = 0; j < DimensoesPecas; j++)
                    PecaArmazenada.grade[i][j] = 0;
            VelocidadePeca = 50; // a velocidade da peça é resetada
            Score = 0; // o score é zerado
            Level = 0;
            PecaGuardada = 0; // essa flag é reiniciada
            jogar = !jogar;
            GameOver = 0;
        }
        if(mouseX >= Botao[5].X1 && mouseX <= Botao[5].X2 && mouseY >= Botao[5].Y1 && mouseY <= Botao[5].Y2 && GameOver == 1)
            exit(0); // fecha o jogo
   }
}

int main(void)
{
    srand(time(NULL));

    for(i = 20; i <= 20; i++) // a linha 20 representa o fundo do tabuleiro por isso inicializei como -1
        for(j = 0; j < ColunasBoard; j++)
            tabuleiro[i][j] = -1;

    TipoProximaPeca = 1 + rand()%7;
    gerarPeca();

    ProximaPeca.posPecaX = x2Tabuleiro + 2 * PixelQuadrado;
    ProximaPeca.posPecaY = y2Tabuleiro + 2 * PixelQuadrado;
    PecaArmazenada.posPecaX = PixelQuadrado * 2;
    PecaArmazenada.posPecaY = y2Tabuleiro + 2 * PixelQuadrado;

    CV::init(&screenWidth, &screenHeight, "Tetris - Augusto Kist Lunardi");

    CV::run();
}
