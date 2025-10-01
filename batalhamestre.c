#include <stdio.h>

#define TAMANHO 10       // tamanho fixo do tabuleiro 10x10
#define TAMANHO_NAVIO 3  // tamanho fixo dos navios (3 casas)
#define TAMANHO_HABIL 5  // tamanho fixo das matrizes de habilidade (5x5)

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidade em cone
void aplicarCone(int tabuleiro[TAMANHO][TAMANHO], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAMANHO_HABIL; i++) {
        for (int j = -i; j <= i; j++) {
            int linha = origemLinha + i;
            int coluna = origemColuna + j;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

// Função para aplicar habilidade em cruz
void aplicarCruz(int tabuleiro[TAMANHO][TAMANHO], int origemLinha, int origemColuna) {
    for (int i = -2; i <= 2; i++) {
        int linha = origemLinha + i;
        int coluna = origemColuna;
        if (linha >= 0 && linha < TAMANHO) {
            if (tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }
    for (int j = -2; j <= 2; j++) {
        int linha = origemLinha;
        int coluna = origemColuna + j;
        if (coluna >= 0 && coluna < TAMANHO) {
            if (tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

// Função para aplicar habilidade em octaedro (losango)
void aplicarOctaedro(int tabuleiro[TAMANHO][TAMANHO], int origemLinha, int origemColuna) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) { // condição para formar o losango
                int linha = origemLinha + i;
                int coluna = origemColuna + j;
                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    // Declarar a matriz do tabuleiro
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializar tabuleiro com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Declarar os navios (representados como vetores de tamanho 3)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};
    int navioDiagonal[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 4; // navio horizontal começa em (2,4)
    int linhaVertical = 5, colunaVertical = 7;     // navio vertical começa em (5,7)
    int linhaDiagonal = 0, colunaDiagonal = 0;     // começa no canto superior esquerdo
    int linhaDiagonal2 = 0, colunaDiagonal2 = 9;   // começa no canto superior direito

    // Colocar o navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Colocar o navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Colocar navios na diagonal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaDiagonal + i][colunaDiagonal + i] == 0) {
            tabuleiro[linhaDiagonal + i][colunaDiagonal + i] = navioDiagonal[i];
        }
        if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] == 0) {
            tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navioDiagonal[i];
        }
    }

    // Aplicar habilidades no tabuleiro
    aplicarCone(tabuleiro, 1, 5);      // cone com origem em (1,5)
    aplicarCruz(tabuleiro, 7, 2);      // cruz com origem em (7,2)
    aplicarOctaedro(tabuleiro, 5, 5);  // octaedro com origem em (5,5)

    // Exibir o tabuleiro final com navios e restantes
    exibirTabuleiro(tabuleiro);

    return 0;
}
