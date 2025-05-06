#include <stdio.h>

#define TAM 8

// =========================
// Funções Recursivas
// =========================

/**
 * Função recursiva para simular o movimento da Torre para cima.
 * @param x Posição atual da linha.
 * @param y Posição atual da coluna (fixa).
 * A cada chamada, imprime "Cima" e move uma linha acima.
 */
void mover_torre(int x, int y) {
    if (x < 0) return;
    printf("Cima\n");
    mover_torre(x - 1, y);
}

/**
 * Função recursiva para simular o movimento da Rainha para a esquerda.
 * @param x Posição atual da linha (fixa).
 * @param y Posição atual da coluna.
 * A cada chamada, imprime "Esquerda" e move uma coluna à esquerda.
 */
void mover_rainha(int x, int y) {
    if (y < 0) return;
    printf("Esquerda\n");
    mover_rainha(x, y - 1);
}

/**
 * Função recursiva para simular o movimento do Bispo em diagonal superior direita.
 * @param x Posição atual da linha.
 * @param y Posição atual da coluna.
 * A cada chamada, imprime "Cima Direita" e move uma linha acima e uma coluna à direita.
 */
void mover_bispo_recursivo(int x, int y) {
    if (x < 0 || y >= TAM) return;
    printf("Cima Direita\n");
    mover_bispo_recursivo(x - 1, y + 1);
}

// =========================
// Bispo com Loops Aninhados (Recursividade + For)
// =========================

/**
 * Função para simular o movimento do Bispo utilizando loops aninhados.
 * Loop externo: variação vertical (linha).
 * Loop interno: variação horizontal (coluna).
 * Apenas os movimentos diagonais (i == j) são considerados válidos.
 * 
 * @param x Posição inicial da linha.
 * @param y Posição inicial da coluna.
 * @param casas Número de casas máximas para mover.
 */
void mover_bispo_loops(int x, int y, int casas) {
    for (int i = 1; i <= casas; i++) {
        for (int j = 1; j <= casas; j++) {
            if (x - i >= 0 && y + j < TAM && i == j) {
                printf("Cima Direita (x-%d y+%d)\n", i, j);
            }
        }
    }
}

// =========================
// Cavalo com Loops Complexos
// =========================

/**
 * Função para simular o movimento do Cavalo usando loops aninhados e controle de fluxo.
 * Filtra apenas o movimento em "L" específico: duas casas para cima e uma para a direita.
 * Usa continue para ignorar outros movimentos e break para interromper o loop em caso nulo.
 * 
 * @param x Posição inicial da linha.
 * @param y Posição inicial da coluna.
 */
void mover_cavalo(int x, int y) {
    printf("Movimentos do Cavalo (duas casas para cima, uma para direita):\n");
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if (dx == -2 && dy == 1) {
                int nx = x + dx;
                int ny = y + dy;

                // Verifica se ainda está dentro do tabuleiro
                if (nx >= 0 && ny < TAM) {
                    printf("Cavalo: Cima Cima Direita\n");
                } else {
                    continue;
                }
            }

            if (dx == -2 && dy != 1) {
                continue; // ignora outros deslocamentos inválidos
            }

            if (dx == 0 && dy == 0) {
                break; // nenhuma movimentação
            }
        }
    }
}

// =========================
// Função Principal
// =========================

/**
 * Função principal do programa.
 * Define a posição inicial e chama as funções de movimentação das peças.
 */
int main() {
    int posX = 4, posY = 4;
    int casas_bispo = 3;

    // Torre (Recursiva)
    printf("Movimentos da Torre:\n");
    mover_torre(posX - 1, posY);  // Começa uma casa acima
    printf("\n");

    // Rainha (Recursiva)
    printf("Movimentos da Rainha:\n");
    mover_rainha(posX, posY - 1);
    printf("\n");

    // Bispo (Recursiva)
    printf("Movimentos do Bispo (Recursiva):\n");
    mover_bispo_recursivo(posX - 1, posY + 1);
    printf("\n");

    // Bispo (Loops Aninhados)
    printf("Movimentos do Bispo (Loops Aninhados):\n");
    mover_bispo_loops(posX, posY, casas_bispo);
    printf("\n");

    // Cavalo (Loops Complexos)
    mover_cavalo(posX, posY);
    printf("\n");

    return 0;
}
