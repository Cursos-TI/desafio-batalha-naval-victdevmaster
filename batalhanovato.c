#include <stdio.h>

#define TAMANHO 10   // tamanho fixo do tabuleiro 10x10
#define TAMANHO_NAVIO 3 // tamanho fixo dos navios (3 casas)

// funçao para o 0 mostrar 
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

int main() {
    // Declarar a matriz do tabuleiro
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializar tabuleiro com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Declarar os navios (representados como vetores de tamanho 3)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 4; // navio horizontal começa em (2,4)
    int linhaVertical = 5, colunaVertical = 7;     // navio vertical começa em (5,7)

    // Colocar o navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Colocar o navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Exibir o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
