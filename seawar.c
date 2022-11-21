#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linhas = 2;
int colunas = 2;

// Inicializa o tabuleiro com -1 em todas as posições
void inicializarTabuleiro(int tab[linhas][colunas])
{
    int coluna, linha;
    
    for (linha = 0; linha < linhas; linha++) {
        for (coluna = 0; coluna < colunas; coluna++) {
            tab[linha][coluna] = -1;
        }
    }
}

// exibe o tabuleiro
void exibirTabuleiro(int tab[linhas][colunas])
{
    int contador, coluna, linha;

    for (contador = 0; contador < colunas; contador++) {
        printf("  %d", contador + 1);
    }
    printf("\n");
    for (linha = 0; linha < linhas; linha++) {
        printf("%d", linha + 1);
        for (coluna = 0; coluna < colunas; coluna++) {
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
void alterarTabuleiro(int tiro[2], int navios[][2], int tabuleiro[][colunas])
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

        // verifica se o navio já não foi criado antes
        for (anterior = 0; anterior < navio; anterior++) {
            // se essa posição já foi usada ele cria outra
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
    printf("Informe a largura do mapa:");
    scanf("%d", &linhas);

    printf("Informe a altura do mapa:");
    scanf("%d", &colunas);

    int tabuleiro[linhas][colunas], navios[3][2], tiro[2], tentativas=0, acertos=0;

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

    printf("\n\n\nJogo terminado. Acertou 3 navios em %d tentativas\n", tentativas);
    exibirTabuleiro(tabuleiro);

    return 0;
}