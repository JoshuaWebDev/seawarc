#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

Há um tabuleiro de 5x5, ou seja, 25 blocos. Há 3 navios escondidos (um em cada bloco).
O objetivo do jogar é descobrir onde estão estes navios e acertá-los.
A cada tiro dado é dito se você acertou algum navio. Caso tenha errado, é dito quantos navios existem naquela linha e naquela coluna.
O jogo só acaba quando você descobrir e afundar os 3 navios.

Legenda pro usuário:
~ : água no bloco. Ainda não foi dado tiro.
* : tiro dado, não há nada ali.
X : tiro dado, havia um navio ali.

Como jogar:
A cada rodada, entre com dois números: o número da linha e o número da coluna onde quer dar o tiro.
Depois é só esperar pra ver se acertou, ou a dica.

Para os programadores C:
O tabuleiro 5x5 é de inteiros. Ele é inicializado com valores '-1'.
A cada tiro ele é atualizado, dependendo se o usuário acertou ou errou. Esses números servirão para exibir '~', '*' ou 'X' para o usuário.
Também servirão para exibir as dicas.

Legenda do tabuleiro:
-1 : nenhum tiro foi dado naquele bloco (~)
 0 : o tiro foi dado e não havia nada (*)
 1 : o usuário atirou e tinha um navio lá (X)

*/

int linhas;
int colunas;

// Inicializa o tabuleiro com -1 em todas as posições
void inicializarTabuleiro(int tab[][5])
{
    int coluna, linha;
    
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            tab[linha][coluna] = -1;
        }
    }
}

// exibe o tabuleiro
void exibirTabuleiro(int tab[][5])
{
    int coluna, linha;

    printf("  1  2  3  4  5 \n");
    for (linha = 0; linha < 5; linha++) {
        printf("%d", linha + 1);
        for (coluna = 0; coluna < 5; coluna++) {
            if (tab[linha][coluna] == -1) {
                printf(" ~ ");
            } else if (tab[linha][coluna] == 0) {
                printf(" * ");
            } else if (tab[linha][coluna] == 1) {
                printf(" # ");
            }
        }
        printf("\n");
    }
}

// altera o tabuleiro
void alterarTabuleiro(int tiro[2], int navios[][2], int tabuleiro[][5])
{
    if(acertou(tiro, navios)) {
        tabuleiro[tiro[0]][tiro[1]]=1;
    } else {
        tabuleiro[tiro[0]][tiro[1]]=0;
    }
}

void criarNavios(int navios[][2])
{
    srand(time(NULL));
    int navio, anterior;

    for (navio = 0; navio < 3; navio++) {
        navios[navio][0] = rand() % 5;
        navios[navio][1] = rand() % 5;

        for (anterior = 0; anterior < navio; anterior++) {
            if ((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1])) {
                do {
                    navios[navio][0] = rand() % 5;
                    navios[navio][1] = rand() % 5;
                } while ((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1]));
            }
        }
    }
}

void atirar(int tiro[2])
{
    // o usuário vai informar um número de 1 a N
    // porém em C os array vai de 0 a N-1
    // por isso o tiro é decrementado em 1
    printf("Linha: ");
    scanf("%d", &tiro[0]);
    tiro[0]--;

    printf("Coluna: ");
    scanf("%d", &tiro[1]);
    tiro[1]--;
}

int acertou(int tiro[2], int navios[][2])
{
    int navio;

    for (navio = 0; navio < 3; navio++) {
        if (tiro[0] == navios[navio][0] && tiro[1] == navios[navio][1]) {
            printf("Acertou em (%d, %d)\n", tiro[0] + 1, tiro[1] + 1);
            return 1;
        }
    }
    return 0;
}

void dica(int tiro[2], int navios[][2], int tentativa)
{
    int linha=0, coluna=0, fila;

    for(fila=0 ; fila < 3 ; fila++) {
        if (navios[fila][0] == tiro[0]) {
            linha++;
        }

        if (navios[fila][1] == tiro[1]) {
            coluna++;
        }
    }

    printf("\nDica %d: \nlinha %d -> %d navios\ncoluna %d -> %d navios\n", tentativa, tiro[0]+1, linha, tiro[1]+1, coluna);
}

int main(void)
{
    int tabuleiro[5][5], navios[3][2], tiro[2], tentativas=0, acertos=0;

    inicializarTabuleiro(tabuleiro);
    criarNavios(navios);

    printf("\n");

    do {
            exibirTabuleiro(tabuleiro);
            atirar(tiro);
            tentativas++;

            if (acertou(tiro, navios)){
                dica(tiro, navios, tentativas);
                acertos++;
            } else {
                dica(tiro, navios, tentativas);
            }

            alterarTabuleiro(tiro, navios, tabuleiro);


    } while (acertos != 3);

    printf("\n\n\nJogo terminado. Acertou 3 navios em %d tentativas", tentativas);
    exibirTabuleiro(tabuleiro);

    return 0;
}