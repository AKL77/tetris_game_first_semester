#include <time.h>

#define PixelQuadrado 30 // O tabuleiro é representa por uma matriz 20 por 10, com quadrados 30 por 30 pixels
#define LinhasBoard 21 // coloquei uma linha extra que representa o fundo do tabuleiro, que foi inicializado com -1 para simplficar as funcoes do jogo
#define ColunasBoard 10
#define x1Tabuleiro 200
#define x2Tabuleiro 500
#define y1Tabuleiro 100
#define y2Tabuleiro 700
#define DimensoesPecas 4 // fiz as matrizes serem 4 por 4 para comportar todas as peças
#define Espacamento 50
#define Alinhamento 10

int i, j, k;

int TipoPeca, TipoProximaPeca;

int ControleVelocidadePeca = 0, VelocidadePeca = 50;

int continuaDescendo, jogar = 0, Options = 0, parar, GameOver = 0, stop, PecaGuardada = 0, HoldChamou, PodeUsarHold = 1;

int screenWidth = 700, screenHeight = 800, AlturaTela = 800;
int mouseX, mouseY;

int SurgimentoInicialPecaX = 290, SurgimentoInicialPecaY = 760;

int tabuleiro[LinhasBoard][ColunasBoard] = {0}, FundoDoTabuleiro = 1;

int Score = 0, Level;
static char score[1];
static char level[1];

int Leaderboard[10] = {0};

struct EstruturaPeca
{
    int grade[DimensoesPecas][DimensoesPecas], posPecaX, posPecaY, EstadoPeca;
};

struct Botoes
{
    int X1, X2, Y1, Y2, Cor;
};

struct EstruturaPeca Piece;
struct EstruturaPeca CopiaPeca;
struct EstruturaPeca ProximaPeca;
struct EstruturaPeca Projecao;
struct EstruturaPeca PecaArmazenada;

struct Botoes Botao[6];

void DesenhaTabuleiro()
{
    CV::color(0.62, 0.12, 0.94); // desenha os quadrados roxos do tabuleiro
    for(i = x1Tabuleiro - PixelQuadrado, j = y2Tabuleiro, k = y1Tabuleiro; i < x2Tabuleiro + PixelQuadrado; i = i + PixelQuadrado)
    {
        CV::rect(i, j, i + PixelQuadrado, j + PixelQuadrado);
        CV::rect(i, k, i + PixelQuadrado, k - PixelQuadrado);
    }
    for(i = y1Tabuleiro, j = x1Tabuleiro, k = x2Tabuleiro; i < y2Tabuleiro; i = i + PixelQuadrado)
    {
        CV::rect(j - PixelQuadrado, i, j, i + PixelQuadrado);
        CV::rect(k, i, k + PixelQuadrado, i + PixelQuadrado);
    }

    sprintf(score, "%d", Score); // imprime o score na tela
    CV::color(1, 1, 0);
    CV::text(x1Tabuleiro - PixelQuadrado, y2Tabuleiro +  PixelQuadrado + Alinhamento, "Score");
    CV::text(x1Tabuleiro + PixelQuadrado, y2Tabuleiro +  PixelQuadrado + Alinhamento, score);

    sprintf(level, "%d", Level); // imprime o level na tela, que aumenta conforme a velocidade das peças aumentam
    CV::color(1, 1, 0);
    CV::text(x1Tabuleiro - PixelQuadrado, y2Tabuleiro + 2 * PixelQuadrado, "Level");
    CV::text(x1Tabuleiro + PixelQuadrado, y2Tabuleiro + 2 * PixelQuadrado, level);

    CV::color(1, 1, 0);
    CV::text(ProximaPeca.posPecaX + PixelQuadrado + Alinhamento, ProximaPeca.posPecaY - PixelQuadrado + Alinhamento, "Next");
    CV::text(PecaArmazenada.posPecaX, PecaArmazenada.posPecaY - PixelQuadrado + Alinhamento, "Hold");

    for(i = 0; i < LinhasBoard; i++) // desenha as peças que foram colocadas no tabuleiro
        for(j = 0; j < ColunasBoard; j++)
            switch (tabuleiro[i][j])
            {
                case 1:
                    CV::color(1, 0.5, 0); // orange
                    CV::rectFill(x1Tabuleiro + j * PixelQuadrado, y2Tabuleiro - i * PixelQuadrado, x1Tabuleiro + (j + 1) * PixelQuadrado, y2Tabuleiro -  (i + 1) * PixelQuadrado);
                    break;

                case 2:
                    CV::color(0.7, 0.10, 0.95); // purple
                    CV::rectFill(x1Tabuleiro + j * PixelQuadrado, y2Tabuleiro - i * PixelQuadrado, x1Tabuleiro + (j + 1) * PixelQuadrado, y2Tabuleiro -  (i + 1) * PixelQuadrado);
                    break;

                case 3:
                    CV::color(1, 1, 0); // yellow
                    CV::rectFill(x1Tabuleiro + j * PixelQuadrado, y2Tabuleiro - i * PixelQuadrado, x1Tabuleiro + (j + 1) * PixelQuadrado, y2Tabuleiro -  (i + 1) * PixelQuadrado);
                    break;

                case 4:
                    CV::color(0, 1, 1); // cyan
                    CV::rectFill(x1Tabuleiro + j * PixelQuadrado, y2Tabuleiro - i * PixelQuadrado, x1Tabuleiro + (j + 1) * PixelQuadrado, y2Tabuleiro -  (i + 1) * PixelQuadrado);
                    break;

                case 5:
                    CV::color(0, 1, 0); // green
                    CV::rectFill(x1Tabuleiro + j * PixelQuadrado, y2Tabuleiro - i * PixelQuadrado, x1Tabuleiro + (j + 1) * PixelQuadrado, y2Tabuleiro -  (i + 1) * PixelQuadrado);
                    break;

                case 6:
                    CV::color(1, 0, 0); // red
                    CV::rectFill(x1Tabuleiro + j * PixelQuadrado, y2Tabuleiro - i * PixelQuadrado, x1Tabuleiro + (j + 1) * PixelQuadrado, y2Tabuleiro -  (i + 1) * PixelQuadrado);
                    break;

                case 7:
                    CV::color(0, 0, 1); // blue
                    CV::rectFill(x1Tabuleiro + j * PixelQuadrado, y2Tabuleiro - i * PixelQuadrado, x1Tabuleiro + (j + 1) * PixelQuadrado, y2Tabuleiro -  (i + 1) * PixelQuadrado);
                    break;
            }

    switch (TipoProximaPeca)
    {
        case 1:
            ProximaPeca.grade[0][0] = 0, ProximaPeca.grade[0][1] = 0, ProximaPeca.grade[0][2] = 0, ProximaPeca.grade[0][3] = 0;
            ProximaPeca.grade[1][0] = 0, ProximaPeca.grade[1][1] = 0, ProximaPeca.grade[1][2] = 0, ProximaPeca.grade[1][3] = 0;
            ProximaPeca.grade[2][0] = 1, ProximaPeca.grade[2][1] = 0, ProximaPeca.grade[2][2] = 0, ProximaPeca.grade[2][3] = 0;
            ProximaPeca.grade[3][0] = 1, ProximaPeca.grade[3][1] = 1, ProximaPeca.grade[3][2] = 1, ProximaPeca.grade[3][3] = 0;
            break;

        case 2:
            ProximaPeca.grade[0][0] = 0, ProximaPeca.grade[0][1] = 0, ProximaPeca.grade[0][2] = 0, ProximaPeca.grade[0][3] = 0;
            ProximaPeca.grade[1][0] = 0, ProximaPeca.grade[1][1] = 0, ProximaPeca.grade[1][2] = 0, ProximaPeca.grade[1][3] = 0;
            ProximaPeca.grade[2][0] = 0, ProximaPeca.grade[2][1] = 2, ProximaPeca.grade[2][2] = 0, ProximaPeca.grade[2][3] = 0;
            ProximaPeca.grade[3][0] = 2, ProximaPeca.grade[3][1] = 2, ProximaPeca.grade[3][2] = 2, ProximaPeca.grade[3][3] = 0;
            break;

        case 3:
            ProximaPeca.grade[0][0] = 0, ProximaPeca.grade[0][1] = 0, ProximaPeca.grade[0][2] = 0, ProximaPeca.grade[0][3] = 0;
            ProximaPeca.grade[1][0] = 0, ProximaPeca.grade[1][1] = 0, ProximaPeca.grade[1][2] = 0, ProximaPeca.grade[1][3] = 0;
            ProximaPeca.grade[2][0] = 0, ProximaPeca.grade[2][1] = 3, ProximaPeca.grade[2][2] = 3, ProximaPeca.grade[2][3] = 0;
            ProximaPeca.grade[3][0] = 0, ProximaPeca.grade[3][1] = 3, ProximaPeca.grade[3][2] = 3, ProximaPeca.grade[3][3] = 0;
            break;

        case 4:
            ProximaPeca.grade[0][0] = 0, ProximaPeca.grade[0][1] = 0, ProximaPeca.grade[0][2] = 0, ProximaPeca.grade[0][3] = 0;
            ProximaPeca.grade[1][0] = 0, ProximaPeca.grade[1][1] = 0, ProximaPeca.grade[1][2] = 0, ProximaPeca.grade[1][3] = 0;
            ProximaPeca.grade[2][0] = 4, ProximaPeca.grade[2][1] = 4, ProximaPeca.grade[2][2] = 4, ProximaPeca.grade[2][3] = 4;
            ProximaPeca.grade[3][0] = 0, ProximaPeca.grade[3][1] = 0, ProximaPeca.grade[3][2] = 0, ProximaPeca.grade[3][3] = 0;
            break;

        case 5:
            ProximaPeca.grade[0][0] = 0, ProximaPeca.grade[0][1] = 0, ProximaPeca.grade[0][2] = 0, ProximaPeca.grade[0][3] = 0;
            ProximaPeca.grade[1][0] = 0, ProximaPeca.grade[1][1] = 0, ProximaPeca.grade[1][2] = 0, ProximaPeca.grade[1][3] = 0;
            ProximaPeca.grade[2][0] = 0, ProximaPeca.grade[2][1] = 5, ProximaPeca.grade[2][2] = 5, ProximaPeca.grade[2][3] = 0;
            ProximaPeca.grade[3][0] = 5, ProximaPeca.grade[3][1] = 5, ProximaPeca.grade[3][2] = 0, ProximaPeca.grade[3][3] = 0;
            break;

        case 6:
            ProximaPeca.grade[0][0] = 0, ProximaPeca.grade[0][1] = 0, ProximaPeca.grade[0][2] = 0, ProximaPeca.grade[0][3] = 0;
            ProximaPeca.grade[1][0] = 0, ProximaPeca.grade[1][1] = 0, ProximaPeca.grade[1][2] = 0, ProximaPeca.grade[1][3] = 0;
            ProximaPeca.grade[2][0] = 6, ProximaPeca.grade[2][1] = 6, ProximaPeca.grade[2][2] = 0, ProximaPeca.grade[2][3] = 0;
            ProximaPeca.grade[3][0] = 0, ProximaPeca.grade[3][1] = 6, ProximaPeca.grade[3][2] = 6, ProximaPeca.grade[3][3] = 0;
            break;

        case 7:
            ProximaPeca.grade[0][0] = 0, ProximaPeca.grade[0][1] = 0, ProximaPeca.grade[0][2] = 0, ProximaPeca.grade[0][3] = 0;
            ProximaPeca.grade[1][0] = 0, ProximaPeca.grade[1][1] = 0, ProximaPeca.grade[1][2] = 0, ProximaPeca.grade[1][3] = 0;
            ProximaPeca.grade[2][0] = 0, ProximaPeca.grade[2][1] = 0, ProximaPeca.grade[2][2] = 7, ProximaPeca.grade[2][3] = 0;
            ProximaPeca.grade[3][0] = 7, ProximaPeca.grade[3][1] = 7, ProximaPeca.grade[3][2] = 7, ProximaPeca.grade[3][3] = 0;
            break;
    }

    for(i = 0; i < DimensoesPecas; i++) // desenha a próxima peça
        for(j = 0; j < DimensoesPecas; j++)
            switch (ProximaPeca.grade[i][j])
            {
                case 1:
                    CV::color(1, 0.5, 0); // laranja
                    CV::rectFill(ProximaPeca.posPecaX + j * PixelQuadrado, ProximaPeca.posPecaY - i * PixelQuadrado,  ProximaPeca.posPecaX + PixelQuadrado * (j + 1), ProximaPeca.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 2:
                    CV::color(0.7, 0.10, 0.95); // roxo
                    CV::rectFill(ProximaPeca.posPecaX + j * PixelQuadrado, ProximaPeca.posPecaY - i * PixelQuadrado,  ProximaPeca.posPecaX + PixelQuadrado * (j + 1), ProximaPeca.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 3:
                    CV::color(1, 1, 0); //amarelo
                    CV::rectFill(ProximaPeca.posPecaX + j * PixelQuadrado, ProximaPeca.posPecaY - i * PixelQuadrado,  ProximaPeca.posPecaX + PixelQuadrado * (j + 1), ProximaPeca.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 4:
                    CV::color(0, 1, 1); // ciano
                    CV::rectFill(ProximaPeca.posPecaX + j * PixelQuadrado, ProximaPeca.posPecaY - i * PixelQuadrado,  ProximaPeca.posPecaX + PixelQuadrado * (j + 1), ProximaPeca.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 5:
                    CV::color(0, 1, 0); // verde
                    CV::rectFill(ProximaPeca.posPecaX + j * PixelQuadrado, ProximaPeca.posPecaY - i * PixelQuadrado,  ProximaPeca.posPecaX + PixelQuadrado * (j + 1), ProximaPeca.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 6:
                    CV::color(1, 0, 0); // vermelho
                    CV::rectFill(ProximaPeca.posPecaX + j * PixelQuadrado, ProximaPeca.posPecaY - i * PixelQuadrado,  ProximaPeca.posPecaX + PixelQuadrado * (j + 1), ProximaPeca.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 7:
                    CV::color(0, 0, 1); // azul
                    CV::rectFill(ProximaPeca.posPecaX + j * PixelQuadrado, ProximaPeca.posPecaY - i * PixelQuadrado,  ProximaPeca.posPecaX + PixelQuadrado * (j + 1), ProximaPeca.posPecaY - PixelQuadrado * (i + 1));
                    break;
            }

    for(i = 0; i < DimensoesPecas; i++) // desenha a peça armazenada na função hold
        for(j = 0; j < DimensoesPecas; j++)
            switch (PecaArmazenada.grade[i][j])
            {
                case 1:
                    CV::color(1, 0.5, 0); // laranja
                    CV::rectFill(PecaArmazenada.posPecaX + j * PixelQuadrado - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - i * PixelQuadrado,  PecaArmazenada.posPecaX + PixelQuadrado * (j + 1) - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 2:
                    CV::color(0.7, 0.10, 0.95); // roxo
                    CV::rectFill(PecaArmazenada.posPecaX + j * PixelQuadrado - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - i * PixelQuadrado,  PecaArmazenada.posPecaX + PixelQuadrado * (j + 1) - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 3:
                    CV::color(1, 1, 0); //amarelo
                    CV::rectFill(PecaArmazenada.posPecaX + j * PixelQuadrado - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - i * PixelQuadrado,  PecaArmazenada.posPecaX + PixelQuadrado * (j + 1) - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 4:
                    CV::color(0, 1, 1); // ciano
                    CV::rectFill(PecaArmazenada.posPecaX + j * PixelQuadrado - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - i * PixelQuadrado,  PecaArmazenada.posPecaX + PixelQuadrado * (j + 1) - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 5:
                    CV::color(0, 1, 0); // verde
                    CV::rectFill(PecaArmazenada.posPecaX + j * PixelQuadrado - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - i * PixelQuadrado,  PecaArmazenada.posPecaX + PixelQuadrado * (j + 1) - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 6:
                    CV::color(1, 0, 0); // vermelho
                    CV::rectFill(PecaArmazenada.posPecaX + j * PixelQuadrado - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - i * PixelQuadrado,  PecaArmazenada.posPecaX + PixelQuadrado * (j + 1) - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 7:
                    CV::color(0, 0, 1); // azul
                    CV::rectFill(PecaArmazenada.posPecaX + j * PixelQuadrado - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - i * PixelQuadrado,  PecaArmazenada.posPecaX + PixelQuadrado * (j + 1) - PixelQuadrado - Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado * (i + 1));
                    break;
            }

    CV::color(0.62, 0.12, 0.94); // desenha as caixinhas roxas do hold e da próxima peça
    CV::line(ProximaPeca.posPecaX - Alinhamento, ProximaPeca.posPecaY - PixelQuadrado, ProximaPeca.posPecaX + 4 * PixelQuadrado + Alinhamento, ProximaPeca.posPecaY - PixelQuadrado);
    CV::line(ProximaPeca.posPecaX - Alinhamento, ProximaPeca.posPecaY - PixelQuadrado, ProximaPeca.posPecaX - Alinhamento, y2Tabuleiro - 2 * PixelQuadrado - Alinhamento);
    CV::line(ProximaPeca.posPecaX - Alinhamento, y2Tabuleiro - 2 * PixelQuadrado - Alinhamento, ProximaPeca.posPecaX + 4 * PixelQuadrado + Alinhamento, y2Tabuleiro - 2 * PixelQuadrado - Alinhamento);
    CV::line(ProximaPeca.posPecaX + 4 * PixelQuadrado + Alinhamento, y2Tabuleiro - 2 * PixelQuadrado - Alinhamento, ProximaPeca.posPecaX + 4 * PixelQuadrado + Alinhamento, ProximaPeca.posPecaY - PixelQuadrado);
    CV::line(PecaArmazenada.posPecaX - PixelQuadrado - 2 * Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado, PecaArmazenada.posPecaX + 2 * PixelQuadrado + 3 * Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado);
    CV::line(PecaArmazenada.posPecaX - PixelQuadrado - 2 * Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado, PecaArmazenada.posPecaX - PixelQuadrado - 2 * Alinhamento, PecaArmazenada.posPecaY - 4 * PixelQuadrado - Alinhamento);
    CV::line(PecaArmazenada.posPecaX - PixelQuadrado -  2 * Alinhamento, PecaArmazenada.posPecaY - 4 * PixelQuadrado - Alinhamento, PecaArmazenada.posPecaX + 2 * PixelQuadrado +  3 * Alinhamento, PecaArmazenada.posPecaY - 4 * PixelQuadrado - Alinhamento);
    CV::line(PecaArmazenada.posPecaX + 2 * PixelQuadrado + 3 * Alinhamento, PecaArmazenada.posPecaY - PixelQuadrado, PecaArmazenada.posPecaX + 2 * PixelQuadrado + 3 * Alinhamento, PecaArmazenada.posPecaY - 4 * PixelQuadrado - Alinhamento);

    CV::color(1, 1, 1); // imprime linhas do board na tela (vertical)
    for(i = y1Tabuleiro; i <= AlturaTela - y1Tabuleiro; i = i + PixelQuadrado)
        CV::line(x1Tabuleiro, AlturaTela - i, y2Tabuleiro - x1Tabuleiro, AlturaTela - i);
    CV::color(1, 1, 1); // imprime linhas do board na tela (horizontal)
    for(i = x1Tabuleiro; i <= y2Tabuleiro - x1Tabuleiro; i = i + PixelQuadrado)
        CV::line(y2Tabuleiro - i, AlturaTela - y1Tabuleiro, y2Tabuleiro - i, y1Tabuleiro);
}

void DesenhaMenu()
{
    Botao[0].X1 = 200; // play
    Botao[0].X2 = 500;
    Botao[0].Y1 = 300;
    Botao[0].Y2 = 400;
    Botao[0].Cor = 1;

    Botao[1].X1 = 200; // options
    Botao[1].X2 = 500;
    Botao[1].Y1 = 100;
    Botao[1].Y2 = 200;
    Botao[1].Cor = 1;

    int Y1Linha = 500, Y2Linha = 600, X1Linha = 25;

    if(mouseX >= Botao[0].X1 && mouseX <= Botao[0].X2 && mouseY >= Botao[0].Y1 && mouseY <= Botao[0].Y2) // controla mundança de cor no botão
        Botao[0].Cor = 0;
    else
        Botao[0].Cor = 1;

    if(mouseX >= Botao[1].X1 && mouseX <= Botao[1].X2 && mouseY >= Botao[1].Y1 && mouseY <= Botao[1].Y2) // controla mundança de cor no botão
        Botao[1].Cor = 0;
    else
        Botao[1].Cor = 1;

    CV::color(1, 1, Botao[0].Cor);
    CV::rect(Botao[0].X1, Botao[0].Y2, Botao[0].X2, Botao[0].Y1);
    CV::text( Botao[0].X2 - Botao[0].X1 + PixelQuadrado, Botao[0].Y1 + Alinhamento * 4 + Alinhamento/2, "Play");

    CV::color(1, 1, Botao[1].Cor);
    CV::rect(Botao[1].X1, Botao[1].Y2, Botao[1].X2, Botao[1].Y1);
    CV::text(Botao[1].X2 - Botao[1].X1 + Alinhamento, Botao[1].Y1 + Alinhamento * 4 + Alinhamento/2, "Options");

    CV::color(1, 1, 0); // Escreve Tetris na tela
    CV::line(X1Linha + Espacamento, Y1Linha, X1Linha + Espacamento, Y2Linha);
    CV::line(X1Linha, Y2Linha, X1Linha + Espacamento * 2, Y2Linha);
    CV::line(Espacamento * 3, Y1Linha, Espacamento * 3, Y2Linha);
    CV::line(Espacamento * 3, Y1Linha, Espacamento * 4, Y1Linha);
    CV::line(Espacamento * 3, Y2Linha, Espacamento * 4, Y2Linha);
    CV::line(Espacamento * 3, (Y1Linha + Y2Linha)/2, Espacamento * 4 - Espacamento/2, (Y1Linha + Y2Linha)/2);
    CV::line(X1Linha + Espacamento * 5, Y1Linha, X1Linha + Espacamento * 5, Y2Linha);
    CV::line(X1Linha + Espacamento * 4, Y2Linha, X1Linha + Espacamento * 6, Y2Linha);
    CV::line(Espacamento * 7, Y1Linha, Espacamento * 7, Y2Linha);
    CV::line(Espacamento * 7, Y2Linha, Espacamento * 8 + Alinhamento, Y2Linha);
    CV::line(Espacamento * 7 + Alinhamento, (Y1Linha + Y2Linha)/2, Espacamento * 8 + Alinhamento, (Y1Linha + Y2Linha)/2);
    CV::line(Espacamento * 7 + Alinhamento, (Y1Linha + Y2Linha)/2, Espacamento * 8 + Alinhamento, Y1Linha);
    CV::line(Espacamento * 8 + Alinhamento, (Y1Linha + Y2Linha)/2, Espacamento * 8 + Alinhamento, Y2Linha);
    CV::line(Espacamento * 9 + X1Linha + Alinhamento, Y1Linha, Espacamento * 9 + X1Linha + Alinhamento, Y2Linha);
    CV::line(Espacamento * 9, Y1Linha, Espacamento * 10 + 2 * Alinhamento, Y1Linha);
    CV::line(Espacamento * 9, Y2Linha, Espacamento * 10 + 2 * Alinhamento, Y2Linha);
    CV::line(Espacamento * 10 + 2 * Alinhamento + X1Linha, Y1Linha, Espacamento * 12 + Alinhamento, Y1Linha);
    CV::line(Espacamento * 12 + Alinhamento, Y1Linha, Espacamento * 12 + Alinhamento, (Y1Linha + Y2Linha)/2);
    CV::line(Espacamento * 10 + 2 * Alinhamento + X1Linha, (Y1Linha + Y2Linha)/2, Espacamento * 12 + Alinhamento, (Y1Linha + Y2Linha)/2);
    CV::line(Espacamento * 10 + 2 * Alinhamento + X1Linha, (Y1Linha + Y2Linha)/2, Espacamento * 10 + 2 * Alinhamento + X1Linha, Y2Linha);
    CV::line(Espacamento * 10 + 2 * Alinhamento + X1Linha, Y2Linha, Espacamento * 12 + Alinhamento, Y2Linha);
}

void Manual()
{
    Botao[2].X1 = 400; // return
    Botao[2].X2 = 600;
    Botao[2].Y1 = 50;
    Botao[2].Y2 = 100;
    Botao[2].Cor = 1;

    int XRect = 100;

    if(mouseX >= Botao[2].X1 && mouseX <= Botao[2].X2 && mouseY >= Botao[2].Y1 && mouseY <= Botao[2].Y2) // controla mudança de cor do botão
        Botao[2].Cor = 0;
    else
        Botao[2].Cor = 1;

    CV::color(1, 1, 1); // Escreve/Desenha na tela as instruções
    for(i = Espacamento * 5; i <= Espacamento * 11; i = i + Espacamento * 2)
        CV::rect(XRect, i, XRect + XRect/2, i + Espacamento);
    CV::rect(XRect, y1Tabuleiro * 2, XRect * 2, y1Tabuleiro + Espacamento);
    CV::rect(x1Tabuleiro/2, y1Tabuleiro, x1Tabuleiro - Espacamento, y1Tabuleiro/2);
    CV::text(x1Tabuleiro + Espacamento, AlturaTela - Espacamento * 2, "How to play the game: ");
    CV::text(x1Tabuleiro/2 + Alinhamento + Alinhamento/2, y1Tabuleiro * 5 + Espacamento + Alinhamento * 2, "->");
    CV::text(x1Tabuleiro - Espacamento/2, y1Tabuleiro * 5 + Espacamento + Alinhamento * 2, "Move Right");
    CV::text(x1Tabuleiro/2 + Alinhamento + Alinhamento/2, y1Tabuleiro * 4 + Espacamento + Alinhamento * 2, "<-");
    CV::text(x1Tabuleiro - Espacamento/2, y1Tabuleiro * 4 + Espacamento + Alinhamento * 2, "Move Left");
    CV::text(Espacamento * 2 + Alinhamento * 2, y1Tabuleiro * 3 + Espacamento + Alinhamento * 2, "|");
    CV::text(x1Tabuleiro - Espacamento/2, y1Tabuleiro * 3 + Espacamento + Alinhamento * 2, "Soft Drop");
    CV::text(Espacamento * 2 + Alinhamento * 2, y1Tabuleiro * 2 + Espacamento + Alinhamento * 2, "|");
    CV::text(x1Tabuleiro - Espacamento/2, y1Tabuleiro * 2 + Espacamento + Alinhamento * 2, "Rotate");
    CV::text(Espacamento * 2 + Espacamento/2, y1Tabuleiro + Espacamento + Alinhamento * 2, "Space");
    CV::text(x1Tabuleiro + Espacamento/2, y1Tabuleiro + Espacamento + Alinhamento * 2, "Hard Drop");
    CV::text(x1Tabuleiro/2 + Alinhamento * 2, y1Tabuleiro - PixelQuadrado, "c");
    CV::text(x1Tabuleiro - PixelQuadrado, y1Tabuleiro - PixelQuadrado, "Hold");
    CV::line(Espacamento * 2 + Alinhamento * 2 - 1, y1Tabuleiro * 3 + Espacamento + Espacamento/2, Espacamento * 2 + Espacamento/2 - 2, y1Tabuleiro * 3 + Espacamento + Alinhamento * 2);
    CV::line(Espacamento * 2 + Espacamento/2 - 1, y1Tabuleiro * 3 + Espacamento + Alinhamento * 2, Espacamento * 2 + Espacamento/2 + 3, y1Tabuleiro * 3 + Espacamento + Alinhamento * 2 + Alinhamento/2);
    CV::line(Espacamento * 2 + Alinhamento * 2, y1Tabuleiro * 2 + Espacamento + Alinhamento * 3, Espacamento * 2 + Alinhamento * 2 + 3, y1Tabuleiro * 2 + Espacamento + Alinhamento * 3 + Alinhamento/2);
    CV::line(Espacamento * 2 + Espacamento/2 + 2, y1Tabuleiro * 2 + Espacamento + Alinhamento * 3, Espacamento * 2 + Espacamento/2 - 2, y1Tabuleiro * 2 + Espacamento + Alinhamento * 3 + Alinhamento/2);

    CV::color(1, 1, Botao[2].Cor);
    CV::rect(Botao[2].X1, Botao[2].Y2, Botao[2].X2, Botao[2].Y1);
    CV::text(x2Tabuleiro - Alinhamento * 2, y1Tabuleiro - Alinhamento * 3, "Done");
}

void FimDeJogo()
{
    CV::color(1, 0, 0); // Desenha Game Over na tela
    CV::line(x1Tabuleiro/2, y2Tabuleiro - Espacamento * 3, x1Tabuleiro/2, y2Tabuleiro);
    CV::line(x1Tabuleiro/2, y2Tabuleiro - Espacamento * 3, x1Tabuleiro, y2Tabuleiro - Espacamento * 3);
    CV::line(x1Tabuleiro/2, y2Tabuleiro, x1Tabuleiro, y2Tabuleiro);
    CV::line(x1Tabuleiro, y2Tabuleiro - Espacamento * 3, x1Tabuleiro, y2Tabuleiro - Espacamento - Espacamento/2);
    CV::line(x1Tabuleiro - Espacamento, y2Tabuleiro - Espacamento - Espacamento/2, x1Tabuleiro, y2Tabuleiro - Espacamento - Espacamento/2);
    CV::line(x1Tabuleiro + Espacamento, y2Tabuleiro - Espacamento * 3, x1Tabuleiro + Espacamento * 2, y2Tabuleiro);
    CV::line(x1Tabuleiro + Espacamento * 2, y2Tabuleiro, x1Tabuleiro + Espacamento * 3, y2Tabuleiro - Espacamento * 3);
    CV::line(x1Tabuleiro + Espacamento + Alinhamento * 2, y2Tabuleiro - Espacamento * 2 + Alinhamento, x1Tabuleiro + Espacamento * 2 + Alinhamento * 3, y2Tabuleiro - Espacamento * 2 + Alinhamento);
    CV::line(x2Tabuleiro - Espacamento * 2, y2Tabuleiro - Espacamento * 3, x2Tabuleiro - Espacamento * 2, y2Tabuleiro);
    CV::line(x2Tabuleiro - Espacamento * 2, y2Tabuleiro, x2Tabuleiro - Espacamento, y2Tabuleiro - Espacamento - Espacamento/2);
    CV::line(x2Tabuleiro - Espacamento, y2Tabuleiro - Espacamento - Espacamento/2, y2Tabuleiro - Espacamento * 4, y2Tabuleiro);
    CV::line(x2Tabuleiro, y2Tabuleiro - Espacamento * 3, x2Tabuleiro, y2Tabuleiro);
    CV::line(x2Tabuleiro + Espacamento, y2Tabuleiro - Espacamento * 3, x2Tabuleiro + Espacamento, y2Tabuleiro);
    CV::line(x2Tabuleiro + Espacamento, y2Tabuleiro, y2Tabuleiro - Espacamento - Espacamento/2, y2Tabuleiro);
    CV::line(x2Tabuleiro + Espacamento, y2Tabuleiro - Espacamento - Espacamento/2, x2Tabuleiro + Espacamento * 2, y2Tabuleiro - Espacamento - Espacamento/2);
    CV::line(x2Tabuleiro + Espacamento, y2Tabuleiro - Espacamento * 3, y2Tabuleiro - Espacamento - Espacamento/2, y2Tabuleiro - Espacamento * 3);
    CV::line(x1Tabuleiro/2, x1Tabuleiro + Espacamento * 3, x1Tabuleiro/2, y2Tabuleiro - Espacamento * 4);
    CV::line(x1Tabuleiro/2, x1Tabuleiro + Espacamento * 3, x1Tabuleiro, x1Tabuleiro + Espacamento * 3);
    CV::line(x1Tabuleiro/2, y2Tabuleiro - Espacamento * 4, x1Tabuleiro, y2Tabuleiro - Espacamento * 4);
    CV::line(x1Tabuleiro, y2Tabuleiro/2, x1Tabuleiro, y2Tabuleiro - Espacamento * 4);
    CV::line(x1Tabuleiro + Espacamento, y2Tabuleiro - Espacamento * 4, x1Tabuleiro + Espacamento * 2, x1Tabuleiro + Espacamento * 3);
    CV::line(x1Tabuleiro + Espacamento * 2, y2Tabuleiro/2, x1Tabuleiro + Espacamento * 3, y2Tabuleiro - Espacamento * 4);
    CV::line(x2Tabuleiro - Espacamento * 2, y2Tabuleiro/2, x2Tabuleiro - Espacamento * 2, y2Tabuleiro - Espacamento * 4);
    CV::line(x2Tabuleiro - Espacamento * 2, y2Tabuleiro - Espacamento * 4, x2Tabuleiro - Espacamento/2, y2Tabuleiro - Espacamento * 4);
    CV::line(x2Tabuleiro - Espacamento * 2, y2Tabuleiro/2, x2Tabuleiro - Espacamento/2, y2Tabuleiro/2);
    CV::line(x2Tabuleiro - Espacamento * 2, y1Tabuleiro * 4 + Espacamento/2, x2Tabuleiro - Espacamento, y1Tabuleiro * 4 + Espacamento/2);
    CV::line(x2Tabuleiro + Espacamento/2, y2Tabuleiro/2, x2Tabuleiro + Espacamento/2, y2Tabuleiro - Espacamento * 4);
    CV::line(x2Tabuleiro + Espacamento/2, y2Tabuleiro - Espacamento * 4, y2Tabuleiro - Espacamento - Espacamento/2, y2Tabuleiro - Espacamento * 4);
    CV::line(y2Tabuleiro - Espacamento - Espacamento/2, y1Tabuleiro * 4 + Espacamento/2, y2Tabuleiro - Espacamento - Espacamento/2, y2Tabuleiro - Espacamento * 4);
    CV::line(x2Tabuleiro + Espacamento + Espacamento/2, y1Tabuleiro * 4 + Espacamento/2, y2Tabuleiro - Espacamento - Espacamento/2, y1Tabuleiro * 4 + Espacamento/2);
    CV::line(x2Tabuleiro + Espacamento + Espacamento/2, y1Tabuleiro * 4 + Espacamento/2, y2Tabuleiro - Espacamento - Espacamento/2, y2Tabuleiro/2);

    sprintf(score, "%d", Score); // imprime o Score na tela
    CV::color(1, 1, 1);
    CV::rect(x1Tabuleiro - Espacamento/2, y1Tabuleiro * 3, x2Tabuleiro - Espacamento/2, y1Tabuleiro * 2 + Espacamento/2);
    CV::text(x1Tabuleiro, y1Tabuleiro * 2 + Espacamento + Alinhamento, "Score:");
    CV::text(x1Tabuleiro + Espacamento + Espacamento/2, y1Tabuleiro * 2 + Espacamento + Alinhamento, score);

    Botao[3].X1 = 50; // play again
    Botao[3].X2 = 250;
    Botao[3].Y1 = 100;
    Botao[3].Y2 = 200;
    Botao[3].Cor = 1;

    Botao[4].X1 = 300; // go to menu
    Botao[4].X2 = 450;
    Botao[4].Y1 = 100;
    Botao[4].Y2 = 200;
    Botao[4].Cor = 1;

    Botao[5].X1 = 500; // exit
    Botao[5].X2 = 650;
    Botao[5].Y1 = 100;
    Botao[5].Y2 = 200;
    Botao[5].Cor = 1;

    if(mouseX >= Botao[3].X1 && mouseX <= Botao[3].X2 && mouseY >= Botao[3].Y1 && mouseY <= Botao[3].Y2) // controla mundaça de cor do botão
        Botao[3].Cor = 0;

    if(mouseX >= Botao[4].X1 && mouseX <= Botao[4].X2 && mouseY >= Botao[4].Y1 && mouseY <= Botao[4].Y2) // controla mundaça de cor do botão
        Botao[4].Cor = 0;

    if(mouseX >= Botao[5].X1 && mouseX <= Botao[5].X2 && mouseY >= Botao[5].Y1 && mouseY <= Botao[5].Y2 ) // controla mundaça de cor do botão
        Botao[5].Cor = 0;

    CV::color(Botao[3].Cor, 1, Botao[3].Cor);
    CV::rect(Botao[3].X1, Botao[3].Y2, Botao[3].X2, Botao[3].Y1);
    CV::text(Botao[3].X1 * 2, Botao[3].Y1 + Alinhamento * 4 + Alinhamento/2, "Play Again");

    CV::color(1, 1, Botao[4].Cor);
    CV::rect(Botao[4].X1, Botao[4].Y2, Botao[4].X2, Botao[4].Y1);
    CV::text(Botao[4].X1 + Espacamento, Botao[4].Y1 + Alinhamento * 4 + Alinhamento/2, "Menu");

    CV::color(1, Botao[5].Cor, Botao[5].Cor);
    CV::rect(Botao[5].X1, Botao[5].Y2, Botao[5].X2, Botao[5].Y1);
    CV::text(Botao[5].X1 + Espacamento, Botao[5].Y1 + Alinhamento * 4 + Alinhamento/2, "Exit");
}

void gerarPeca() // gera uma nova peça aleatoriamente
{
    if(HoldChamou == 0) // foi preciso colocar essa flag, pois sem ela o valor do TipoPeca seria a da próxima peca e nao a da peça guardada pela função hold
    {
        TipoPeca = TipoProximaPeca;
        TipoProximaPeca = 1 + rand()%7;
    }

    Piece.posPecaX = SurgimentoInicialPecaX;
    Piece.posPecaY = SurgimentoInicialPecaY;

    switch (TipoPeca) // preenche a peça baseado no tipo de peça sorteado
    {
        case 1:
            Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
            Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
            Piece.grade[2][0] = 1, Piece.grade[2][1] = 0, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
            Piece.grade[3][0] = 1, Piece.grade[3][1] = 1, Piece.grade[3][2] = 1, Piece.grade[3][3] = 0;
            Piece.EstadoPeca = 0;
            break;

        case 2:
            Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
            Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
            Piece.grade[2][0] = 0, Piece.grade[2][1] = 2, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
            Piece.grade[3][0] = 2, Piece.grade[3][1] = 2, Piece.grade[3][2] = 2, Piece.grade[3][3] = 0;
            Piece.EstadoPeca = 0;
            break;

        case 3:
            Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
            Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
            Piece.grade[2][0] = 0, Piece.grade[2][1] = 3, Piece.grade[2][2] = 3, Piece.grade[2][3] = 0;
            Piece.grade[3][0] = 0, Piece.grade[3][1] = 3, Piece.grade[3][2] = 3, Piece.grade[3][3] = 0;
            Piece.EstadoPeca = 0;
            break;

        case 4:
            Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
            Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
            Piece.grade[2][0] = 4, Piece.grade[2][1] = 4, Piece.grade[2][2] = 4, Piece.grade[2][3] = 4;
            Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
            Piece.EstadoPeca = 0;
            break;

        case 5:
            Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
            Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
            Piece.grade[2][0] = 0, Piece.grade[2][1] = 5, Piece.grade[2][2] = 5, Piece.grade[2][3] = 0;
            Piece.grade[3][0] = 5, Piece.grade[3][1] = 5, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
            Piece.EstadoPeca = 0;
            break;

        case 6:
            Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
            Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
            Piece.grade[2][0] = 6, Piece.grade[2][1] = 6, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
            Piece.grade[3][0] = 0, Piece.grade[3][1] = 6, Piece.grade[3][2] = 6, Piece.grade[3][3] = 0;
            Piece.EstadoPeca = 0;
            break;

        case 7:
            Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
            Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
            Piece.grade[2][0] = 0, Piece.grade[2][1] = 0, Piece.grade[2][2] = 7, Piece.grade[2][3] = 0;
            Piece.grade[3][0] = 7, Piece.grade[3][1] = 7, Piece.grade[3][2] = 7, Piece.grade[3][3] = 0;
            Piece.EstadoPeca = 0;
            break;
    }

    if((TipoPeca != 4 && tabuleiro[1][4]) != 0 || (TipoPeca == 4 && tabuleiro[0][4] != 0)) // controla o game over, caso uma nova peça seja gerada num local já ocupado, o jogo acaba
        GameOver = 1;

    continuaDescendo = 1;
}

void AdicionaPecaTabuleiro() // atualiza os valores da matriz do tabuleiro conforme as peças vão caindo
{
    for(i = 0; i < DimensoesPecas; i++) // as coordenadas são transformadas em indices para a matriz do tabuleiro
        for(j = 0; j < DimensoesPecas; j++)
            if(Piece.grade[i][j] != 0)
                tabuleiro[(y2Tabuleiro - (Piece.posPecaY - i * PixelQuadrado))/PixelQuadrado][(Piece.posPecaX + j * PixelQuadrado - x1Tabuleiro)/PixelQuadrado] = Piece.grade[i][j];

    Score += 10;
}

void eliminaLinha() // caso uma linha seja preenchida, ela será eliminada e as peças acima cairão uma linha
{
    int cont = 0, ComboLinhas = 0, PontosNessaRodada = 0;

    for(i = 0; i < LinhasBoard - FundoDoTabuleiro; i++)
    {
        for(j = 0; j < ColunasBoard; j++)
            if(tabuleiro[i][j] == 0)
                cont++; // funciona para verificar se ha um 0 na linha
        if(cont == 0) // caso nao haja 0, significa que a linha está preenchida
        {
            for(int L = i; L <= i; L++)
            {
                for(int C = 0; C < ColunasBoard; C++) // a linha que estava preenchida com peças é esvaziada
                    tabuleiro[L][C] = 0;
                ComboLinhas++; // conta quantas linhas foram eliminadas simultaneamente
            }
        for(k = i; k >= 1; k--)
            for(int q = 0; q < ColunasBoard; q++)
                tabuleiro[k][q] = tabuleiro[k - 1][q]; // as peças acima da linha que foi preenchida descem uma linha
        for(int z = 0; z <= 0; z++)
            for(int p = 0; p < ColunasBoard; p++)
                tabuleiro[z][p] = 0; // a linha 0 é zerada
        }
        cont = 0;
    }

    switch (ComboLinhas) // o jogador recebe pontos extras quanto mais linhas o jogador consegue eliminar simultaneamente
    {
        case 0:
        PontosNessaRodada = 0;
        break;

        case 1:
        PontosNessaRodada = 100;
        break;

        case 2:
        PontosNessaRodada = 200;
        break;

        case 3:
        PontosNessaRodada = 400;
        break;

        case 4:
        PontosNessaRodada = 800;
        break;
    }

    Score += PontosNessaRodada;

    VelocidadePeca = 50 - Score/250; // a velocidade da peça é baseada na pontuação, ou seja, quanto maior for a pontuação do jogador, mais rápido as peças ficam

    if(VelocidadePeca >= 0)
        Level = 50 - VelocidadePeca;
}

void descePeca() // verifica se a peça pode descer uma linha, é checado se a linha que a peça está + 1 está ja preenchida, caso esteja e a peça descer, a peça será congelada nessa posição
{
    parar = 0; // flag que informa se a peça pode continuar descendo, caso seja = 1 a peça não pode descer

    for(i = 0; i < DimensoesPecas; i++)
        for(j = 0; j < DimensoesPecas; j++)
            if(Piece.grade[i][j] != 0 && tabuleiro[((y2Tabuleiro - (Piece.posPecaY - i * PixelQuadrado))/PixelQuadrado) + 1][(Piece.posPecaX + j * PixelQuadrado - x1Tabuleiro)/PixelQuadrado] != 0)
                parar = 1;

    if(parar == 0)
    {
        Piece.posPecaY -= PixelQuadrado;
        ControleVelocidadePeca = 0;
    }
    else
    {
        continuaDescendo = 0;
        HoldChamou = 0;
        PodeUsarHold = 1; // faz com que o jogador possa usar o hold novamente
        AdicionaPecaTabuleiro();
        eliminaLinha();
        gerarPeca();
    }
}

void ProjecaoDaPeca()
{
    for (i = 0; i < DimensoesPecas; i++) // a projecao da peca é uma copia da peca original no menor Y possivel
        for(j = 0; j < DimensoesPecas; j++)
            Projecao.grade[i][j] = Piece.grade[i][j];

    Projecao.posPecaX = Piece.posPecaX;
    Projecao.posPecaY = Piece.posPecaY;

    stop = 0;

    while(stop != 1) // encontra o menor Y possivel que a peça vai ficar
    {
        for(i = 0; i < DimensoesPecas; i++)
            for(j = 0; j < DimensoesPecas; j++)
                if(Projecao.grade[i][j] != 0 && tabuleiro[((y2Tabuleiro - (Projecao.posPecaY - i * PixelQuadrado))/PixelQuadrado) + 1][(Projecao.posPecaX + j * PixelQuadrado - x1Tabuleiro)/PixelQuadrado] != 0)
                    stop = 1;
        if(stop != 1)
            Projecao.posPecaY -= PixelQuadrado;
    }

    for(i = 0; i < DimensoesPecas; i++) // desenha a projecao da peça
        for(j = 0; j < DimensoesPecas; j++)
            if(Projecao.grade[i][j] != 0)
            {
                CV::color(0.5, 0.5, 0.5); // gray
                CV::rectFill(Projecao.posPecaX + j * PixelQuadrado, Projecao.posPecaY - i * PixelQuadrado,  Projecao.posPecaX + PixelQuadrado * (j + 1), Projecao.posPecaY - PixelQuadrado * (i + 1));
            }
}

void DesenhaPeca() // Desenha a peça que está caindo baseado na sua posicao X e Y e são pintados os valores da peça diferentes de 0
{
    ProjecaoDaPeca();

    for(i = 0; i < DimensoesPecas; i++) // desenha a peça caindo
        for(j = 0; j < DimensoesPecas; j++)
            switch (Piece.grade[i][j])
            {
                case 1:
                    CV::color(1, 0.5, 0); // laranja
                    CV::rectFill(Piece.posPecaX + j * PixelQuadrado, Piece.posPecaY - i * PixelQuadrado,  Piece.posPecaX + PixelQuadrado * (j + 1), Piece.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 2:
                    CV::color(0.7, 0.10, 0.95); // roxo
                    CV::rectFill(Piece.posPecaX + j * PixelQuadrado, Piece.posPecaY - i * PixelQuadrado,  Piece.posPecaX + PixelQuadrado * (j + 1), Piece.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 3:
                    CV::color(1, 1, 0); //amarelo
                    CV::rectFill(Piece.posPecaX + j * PixelQuadrado, Piece.posPecaY - i * PixelQuadrado,  Piece.posPecaX + PixelQuadrado * (j + 1), Piece.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 4:
                    CV::color(0, 1, 1); // ciano
                    CV::rectFill(Piece.posPecaX + j * PixelQuadrado, Piece.posPecaY - i * PixelQuadrado,  Piece.posPecaX + PixelQuadrado * (j + 1), Piece.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 5:
                    CV::color(0, 1, 0); // verde
                    CV::rectFill(Piece.posPecaX + j * PixelQuadrado, Piece.posPecaY - i * PixelQuadrado,  Piece.posPecaX + PixelQuadrado * (j + 1), Piece.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 6:
                    CV::color(1, 0, 0); // vermelho
                    CV::rectFill(Piece.posPecaX + j * PixelQuadrado, Piece.posPecaY - i * PixelQuadrado,  Piece.posPecaX + PixelQuadrado * (j + 1), Piece.posPecaY - PixelQuadrado * (i + 1));
                    break;

                case 7:
                    CV::color(0, 0, 1); // azul
                    CV::rectFill(Piece.posPecaX + j * PixelQuadrado, Piece.posPecaY - i * PixelQuadrado,  Piece.posPecaX + PixelQuadrado * (j + 1), Piece.posPecaY - PixelQuadrado * (i + 1));
                    break;
            }

   if(continuaDescendo == 1 && ControleVelocidadePeca > VelocidadePeca)
        descePeca();
}

void hold()
{
    int aux; //
    if(PecaGuardada == 0) // caso nao tenha nada armazenado ainda na função hold
    {
        PecaGuardada = TipoPeca;
        TipoPeca = TipoProximaPeca;
    }
    else
    {
        aux = TipoPeca;
        TipoPeca = PecaGuardada;
        PecaGuardada = aux;
    }

    switch (aux) // preenche a varival PecaArmazenada.grade para ser pintada na funcao DesenhaTabuleiro
    {
        case 1:
            PecaArmazenada.grade[0][0] = 0, PecaArmazenada.grade[0][1] = 0, PecaArmazenada.grade[0][2] = 0, PecaArmazenada.grade[0][3] = 0;
            PecaArmazenada.grade[1][0] = 0, PecaArmazenada.grade[1][1] = 0, PecaArmazenada.grade[1][2] = 0, PecaArmazenada.grade[1][3] = 0;
            PecaArmazenada.grade[2][0] = 1, PecaArmazenada.grade[2][1] = 0, PecaArmazenada.grade[2][2] = 0, PecaArmazenada.grade[2][3] = 0;
            PecaArmazenada.grade[3][0] = 1, PecaArmazenada.grade[3][1] = 1, PecaArmazenada.grade[3][2] = 1, PecaArmazenada.grade[3][3] = 0;
            break;

        case 2:
            PecaArmazenada.grade[0][0] = 0, PecaArmazenada.grade[0][1] = 0, PecaArmazenada.grade[0][2] = 0, PecaArmazenada.grade[0][3] = 0;
            PecaArmazenada.grade[1][0] = 0, PecaArmazenada.grade[1][1] = 0, PecaArmazenada.grade[1][2] = 0, PecaArmazenada.grade[1][3] = 0;
            PecaArmazenada.grade[2][0] = 0, PecaArmazenada.grade[2][1] = 2, PecaArmazenada.grade[2][2] = 0, PecaArmazenada.grade[2][3] = 0;
            PecaArmazenada.grade[3][0] = 2, PecaArmazenada.grade[3][1] = 2, PecaArmazenada.grade[3][2] = 2, PecaArmazenada.grade[3][3] = 0;
            break;

        case 3:
            PecaArmazenada.grade[0][0] = 0, PecaArmazenada.grade[0][1] = 0, PecaArmazenada.grade[0][2] = 0, PecaArmazenada.grade[0][3] = 0;
            PecaArmazenada.grade[1][0] = 0, PecaArmazenada.grade[1][1] = 0, PecaArmazenada.grade[1][2] = 0, PecaArmazenada.grade[1][3] = 0;
            PecaArmazenada.grade[2][0] = 0, PecaArmazenada.grade[2][1] = 3, PecaArmazenada.grade[2][2] = 3, PecaArmazenada.grade[2][3] = 0;
            PecaArmazenada.grade[3][0] = 0, PecaArmazenada.grade[3][1] = 3, PecaArmazenada.grade[3][2] = 3, PecaArmazenada.grade[3][3] = 0;
            break;

        case 4:
            PecaArmazenada.grade[0][0] = 0, PecaArmazenada.grade[0][1] = 0, PecaArmazenada.grade[0][2] = 0, PecaArmazenada.grade[0][3] = 0;
            PecaArmazenada.grade[1][0] = 0, PecaArmazenada.grade[1][1] = 0, PecaArmazenada.grade[1][2] = 0, PecaArmazenada.grade[1][3] = 0;
            PecaArmazenada.grade[2][0] = 4, PecaArmazenada.grade[2][1] = 4, PecaArmazenada.grade[2][2] = 4, PecaArmazenada.grade[2][3] = 4;
            PecaArmazenada.grade[3][0] = 0, PecaArmazenada.grade[3][1] = 0, PecaArmazenada.grade[3][2] = 0, PecaArmazenada.grade[3][3] = 0;
            break;

        case 5:
            PecaArmazenada.grade[0][0] = 0, PecaArmazenada.grade[0][1] = 0, PecaArmazenada.grade[0][2] = 0, PecaArmazenada.grade[0][3] = 0;
            PecaArmazenada.grade[1][0] = 0, PecaArmazenada.grade[1][1] = 0, PecaArmazenada.grade[1][2] = 0, PecaArmazenada.grade[1][3] = 0;
            PecaArmazenada.grade[2][0] = 0, PecaArmazenada.grade[2][1] = 5, PecaArmazenada.grade[2][2] = 5, PecaArmazenada.grade[2][3] = 0;
            PecaArmazenada.grade[3][0] = 5, PecaArmazenada.grade[3][1] = 5, PecaArmazenada.grade[3][2] = 0, PecaArmazenada.grade[3][3] = 0;
            break;

        case 6:
            PecaArmazenada.grade[0][0] = 0, PecaArmazenada.grade[0][1] = 0, PecaArmazenada.grade[0][2] = 0, PecaArmazenada.grade[0][3] = 0;
            PecaArmazenada.grade[1][0] = 0, PecaArmazenada.grade[1][1] = 0, PecaArmazenada.grade[1][2] = 0, PecaArmazenada.grade[1][3] = 0;
            PecaArmazenada.grade[2][0] = 6, PecaArmazenada.grade[2][1] = 6, PecaArmazenada.grade[2][2] = 0, PecaArmazenada.grade[2][3] = 0;
            PecaArmazenada.grade[3][0] = 0, PecaArmazenada.grade[3][1] = 6, PecaArmazenada.grade[3][2] = 6, PecaArmazenada.grade[3][3] = 0;
            break;

        case 7:
            PecaArmazenada.grade[0][0] = 0, PecaArmazenada.grade[0][1] = 0, PecaArmazenada.grade[0][2] = 0, PecaArmazenada.grade[0][3] = 0;
            PecaArmazenada.grade[1][0] = 0, PecaArmazenada.grade[1][1] = 0, PecaArmazenada.grade[1][2] = 0, PecaArmazenada.grade[1][3] = 0;
            PecaArmazenada.grade[2][0] = 0, PecaArmazenada.grade[2][1] = 0, PecaArmazenada.grade[2][2] = 7, PecaArmazenada.grade[2][3] = 0;
            PecaArmazenada.grade[3][0] = 7, PecaArmazenada.grade[3][1] = 7, PecaArmazenada.grade[3][2] = 7, PecaArmazenada.grade[3][3] = 0;
            break;
    }

    HoldChamou = 1;

    PodeUsarHold = 0; // faz com que o jogador nao possa chamar a hold infinitamente, só poderá chamá-la novamente depois que uma oeça for colocada no tabuleiro

    gerarPeca(); // atualiza os valores da peca
}

void MoveDireita() // verifica se pode ir pra direira
{
    int PodeMoverDireita = 1;

    for(i = 0; i < DimensoesPecas; i++)
        for(j = 0; j < DimensoesPecas; j++)
        {
            if(Piece.grade[i][j] != 0 && (Piece.posPecaX + j * PixelQuadrado) > x2Tabuleiro - 2 * PixelQuadrado) // detecta colisão com a borda direita do tabuleiro
               PodeMoverDireita = 0;
            if(Piece.grade[i][j] != 0 && tabuleiro[(y2Tabuleiro - (Piece.posPecaY - i * PixelQuadrado))/PixelQuadrado][((Piece.posPecaX + j * PixelQuadrado - x1Tabuleiro)/PixelQuadrado) + 1] != 0)
                PodeMoverDireita = 0; // detecta colisão com as peças
        }

    if(PodeMoverDireita == 1)
        Piece.posPecaX += PixelQuadrado;
}

void MoveEsquerda() // verifica se pode ir pra esquerda
{
    int PodeMoverEsquerda = 1;

    for(i = 0; i < DimensoesPecas; i++)
        for(j = 0; j < DimensoesPecas; j++)
        {
            if(Piece.grade[i][j] != 0 && (Piece.posPecaX + j * PixelQuadrado) < x1Tabuleiro + PixelQuadrado) // detecta colisão com a borda esquerda do tabuleiro
               PodeMoverEsquerda = 0;
            if(Piece.grade[i][j] != 0 && tabuleiro[(y2Tabuleiro - (Piece.posPecaY - i * PixelQuadrado))/PixelQuadrado][((Piece.posPecaX + j * PixelQuadrado - x1Tabuleiro)/PixelQuadrado) - 1] != 0)
                PodeMoverEsquerda = 0; // detecta colisão com as peças
        }

    if(PodeMoverEsquerda == 1)
        Piece.posPecaX -= PixelQuadrado;
}

int VerificaSePodeGirar() // verifica se a peca pode ser girada
{
    for(i = 0; i < DimensoesPecas; i++)
        for(j = 0; j < DimensoesPecas; j++)
            CopiaPeca.grade[i][j] = Piece.grade[i][j];

    CopiaPeca.EstadoPeca = Piece.EstadoPeca;
    CopiaPeca.posPecaX = Piece.posPecaX;
    CopiaPeca.posPecaY = Piece.posPecaY;

    int NaoPodeGirar = 0;

    switch (TipoPeca)
        {
            case 1:
                switch (CopiaPeca.EstadoPeca)
                {
                    case 0:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 1, CopiaPeca.grade[1][1] = 1, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 1, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 1, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 1;
                        break;

                    case 1:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 1, CopiaPeca.grade[1][1] = 1, CopiaPeca.grade[1][2] = 1, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 1, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 2;
                        break;

                    case 2:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 1, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 1, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 1, CopiaPeca.grade[3][2] = 1, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 3;
                        break;

                    case 3:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 1, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 1, CopiaPeca.grade[3][1] = 1, CopiaPeca.grade[3][2] = 1, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 0;
                    break;
                }
                break;

            case 2:
                switch (CopiaPeca.EstadoPeca)
                {
                    case 0:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 2, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 2, CopiaPeca.grade[2][1] = 2, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 2, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 1;
                        break;

                    case 1:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 2, CopiaPeca.grade[1][1] = 2, CopiaPeca.grade[1][2] = 2, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 2, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 2;
                        break;

                    case 2:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 2, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 2, CopiaPeca.grade[2][2] = 2, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 2, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 3;
                        break;

                    case 3:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 2, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 2, CopiaPeca.grade[3][1] = 2, CopiaPeca.grade[3][2] = 2, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 0;
                        break;
                }
                break;

            case 3:
                break;

            case 4:
                switch(CopiaPeca.EstadoPeca)
                {
                    case 0:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 4, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 4, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 4, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 4, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 1;
                        break;

                    case 1:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 4, CopiaPeca.grade[2][1] = 4, CopiaPeca.grade[2][2] = 4, CopiaPeca.grade[2][3] = 4;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 0;
                        break;
                }
                break;

            case 5:
                switch(CopiaPeca.EstadoPeca)
                {
                    case 0:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 5, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 5, CopiaPeca.grade[2][2] = 5, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 5, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 1;
                        break;

                    case 1:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 5, CopiaPeca.grade[2][2] = 5, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 5, CopiaPeca.grade[3][1] = 5, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 0;
                        break;
                }
                break;

            case 6:
                switch (CopiaPeca.EstadoPeca)
                {
                    case 0:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 6, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 6, CopiaPeca.grade[2][1] = 6, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 6, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 1;
                        break;

                    case 1:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 6, CopiaPeca.grade[2][1] = 6, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 6, CopiaPeca.grade[3][2] = 6, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 0;
                        break;
                }
                break;

            case 7:
                switch (CopiaPeca.EstadoPeca)
                {
                    case 0:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 7, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 7, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 7, CopiaPeca.grade[3][1] = 7, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 1;
                        break;

                    case 1:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 7, CopiaPeca.grade[1][1] = 7, CopiaPeca.grade[1][2] = 7, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 7, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 0, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 0, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 2;
                        break;

                    case 2:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 7, CopiaPeca.grade[1][2] = 7, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 7, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 0, CopiaPeca.grade[3][1] = 0, CopiaPeca.grade[3][2] = 7, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 3;
                        break;

                    case 3:
                        CopiaPeca.grade[0][0] = 0, CopiaPeca.grade[0][1] = 0, CopiaPeca.grade[0][2] = 0, CopiaPeca.grade[0][3] = 0;
                        CopiaPeca.grade[1][0] = 0, CopiaPeca.grade[1][1] = 0, CopiaPeca.grade[1][2] = 0, CopiaPeca.grade[1][3] = 0;
                        CopiaPeca.grade[2][0] = 0, CopiaPeca.grade[2][1] = 0, CopiaPeca.grade[2][2] = 7, CopiaPeca.grade[2][3] = 0;
                        CopiaPeca.grade[3][0] = 7, CopiaPeca.grade[3][1] = 7, CopiaPeca.grade[3][2] = 7, CopiaPeca.grade[3][3] = 0;
                        CopiaPeca.EstadoPeca = 0;
                    break;
                }
                break;
        }

    for(i = 0; i < DimensoesPecas; i++) // aq é onde a verificação é feita se a peça pode girar ou nao, baseado na copia da peça que é girada para simular a possível posição ocupada pela peça
        for(j = 0; j < DimensoesPecas; j++)
        {
            if(CopiaPeca.grade[i][j] != 0 && tabuleiro[(y2Tabuleiro - (CopiaPeca.posPecaY - i * PixelQuadrado))/PixelQuadrado][(CopiaPeca.posPecaX + j * PixelQuadrado - x1Tabuleiro)/PixelQuadrado] != 0)
                NaoPodeGirar = 1;
            if(CopiaPeca.grade[i][j] != 0 && (CopiaPeca.posPecaX + j * PixelQuadrado) > x2Tabuleiro - PixelQuadrado)
                NaoPodeGirar = 1;
            if(CopiaPeca.grade[i][j] != 0 && (CopiaPeca.posPecaX + j * PixelQuadrado) < x1Tabuleiro)
                NaoPodeGirar = 1;
            if(CopiaPeca.grade[i][j] != 0 && (CopiaPeca.posPecaY + i * PixelQuadrado) > 820)
                NaoPodeGirar = 1;
            if(TipoPeca == 4 && CopiaPeca.grade[i][j] != 0 && (CopiaPeca.posPecaY + i * PixelQuadrado) > 790)
                NaoPodeGirar = 1;
        }

    return NaoPodeGirar; // se nao for possivel girar o valor retornado sera 1, do contrário, será 0
}

void giraPeca() // gira a peça
{
    int NaoDaParaGirar = VerificaSePodeGirar(); // verifica se é possível girar a peça

    if(NaoDaParaGirar == 0)
        switch (TipoPeca) // gira os diferentes tipos de peça
        {
            case 1:
                switch (Piece.EstadoPeca)
                {
                    case 0:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 1, Piece.grade[1][1] = 1, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 1, Piece.grade[2][1] = 0, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 1, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 1;
                        break;

                    case 1:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 1, Piece.grade[1][1] = 1, Piece.grade[1][2] = 1, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 0, Piece.grade[2][2] = 1, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 2;
                        break;

                    case 2:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 1, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 0, Piece.grade[2][2] = 1, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 1, Piece.grade[3][2] = 1, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 3;
                        break;

                    case 3:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 1, Piece.grade[2][1] = 0, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 1, Piece.grade[3][1] = 1, Piece.grade[3][2] = 1, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 0;
                        break;
                }
                break;

            case 2:
                switch (Piece.EstadoPeca)
                {
                    case 0:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 2, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 2, Piece.grade[2][1] = 2, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 2, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 1;
                        break;

                    case 1:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 2, Piece.grade[1][1] = 2, Piece.grade[1][2] = 2, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 2, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 2;
                        break;

                    case 2:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 2, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 2, Piece.grade[2][2] = 2, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 2, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 3;
                        break;

                    case 3:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 2, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 2, Piece.grade[3][1] = 2, Piece.grade[3][2] = 2, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 0;
                        break;
                }
                break;

            case 3:
                break;

            case 4:
                switch (Piece.EstadoPeca)
                {
                    case 0:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 4, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 4, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 4, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 4, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 1;
                        break;

                    case 1:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 4, Piece.grade[2][1] = 4, Piece.grade[2][2] = 4, Piece.grade[2][3] = 4;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 0;
                        break;
                }
                break;

            case 5:
                switch (Piece.EstadoPeca)
                {
                    case 0:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 5, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 5, Piece.grade[2][2] = 5, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 5, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 1;
                        break;

                    case 1:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 5, Piece.grade[2][2] = 5, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 5, Piece.grade[3][1] = 5, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 0;
                        break;
                }
                break;

            case 6:
                switch (Piece.EstadoPeca)
                {
                    case 0:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 6, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 6, Piece.grade[2][1] = 6, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 6, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 1;
                        break;

                    case 1:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 6, Piece.grade[2][1] = 6, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 6, Piece.grade[3][2] = 6, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 0;
                        break;
                }
                break;

            case 7:
                switch (Piece.EstadoPeca)
                {
                    case 0:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 7, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 7, Piece.grade[2][1] = 0, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 7, Piece.grade[3][1] = 7, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 1;
                        break;

                    case 1:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 7, Piece.grade[1][1] = 7, Piece.grade[1][2] = 7, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 7, Piece.grade[2][1] = 0, Piece.grade[2][2] = 0, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 0, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 2;
                        break;

                    case 2:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 7, Piece.grade[1][2] = 7, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 0, Piece.grade[2][2] = 7, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 0, Piece.grade[3][1] = 0, Piece.grade[3][2] = 7, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 3;
                        break;

                    case 3:
                        Piece.grade[0][0] = 0, Piece.grade[0][1] = 0, Piece.grade[0][2] = 0, Piece.grade[0][3] = 0;
                        Piece.grade[1][0] = 0, Piece.grade[1][1] = 0, Piece.grade[1][2] = 0, Piece.grade[1][3] = 0;
                        Piece.grade[2][0] = 0, Piece.grade[2][1] = 0, Piece.grade[2][2] = 7, Piece.grade[2][3] = 0;
                        Piece.grade[3][0] = 7, Piece.grade[3][1] = 7, Piece.grade[3][2] = 7, Piece.grade[3][3] = 0;
                        Piece.EstadoPeca = 0;
                        break;
                }
                break;
        }
}
