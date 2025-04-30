#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
// Tamanho fixo dos navios
#define TAM_NAVIO 3
// Valor que representa um navio no tabuleiro
#define NAVIO 3
// Valor que representa água no tabuleiro
#define AGUA 0

int main() {
    // Declaração da matriz do tabuleiro e inicialização com água (0)
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa todas as posições da matriz com 0
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Definição dos dois navios (tamanho 3)
    int navio1[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Navio horizontal
    int navio2[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Navio vertical

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaNavio1 = 2, colunaNavio1 = 3; // Navio 1 - horizontal
    int linhaNavio2 = 5, colunaNavio2 = 7; // Navio 2 - vertical

    // Validação para o navio 1 (horizontal)
    if (colunaNavio1 + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica se há sobreposição
            if (tabuleiro[linhaNavio1][colunaNavio1 + i] != AGUA) {
                printf("Erro: Sobreposição detectada para o Navio 1.\n");
                return 1;
            }
            tabuleiro[linhaNavio1][colunaNavio1 + i] = navio1[i];
        }
    } else {
        printf("Erro: Navio 1 (horizontal) fora dos limites.\n");
        return 1;
    }

    // Validação para o navio 2 (vertical)
    if (linhaNavio2 + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica se há sobreposição
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] != AGUA) {
                printf("Erro: Sobreposição detectada para o Navio 2.\n");
                return 1;
            }
            tabuleiro[linhaNavio2 + i][colunaNavio2] = navio2[i];
        }
    } else {
        printf("Erro: Navio 2 (vertical) fora dos limites.\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("\n===== TABULEIRO BATALHA NAVAL (10x10) =====\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
