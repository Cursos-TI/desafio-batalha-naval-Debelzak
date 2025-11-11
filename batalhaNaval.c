#include <stdio.h>

#define BOARD_SIZE_X 10
#define BOARD_SIZE_Y 10

// =======================================================
// Funções de desenho de navios
// =======================================================

// Navio horizontal (→)
void drawHorizontalShip(int board[BOARD_SIZE_Y][BOARD_SIZE_X], int x, int y, int size, int id) {
    for (int i = 0; i < size; i++) {
        int px = x + i;
        if (px < BOARD_SIZE_X && y < BOARD_SIZE_Y)
            board[y][px] = id;
    }
}

// Navio vertical (↓)
void drawVerticalShip(int board[BOARD_SIZE_Y][BOARD_SIZE_X], int x, int y, int size, int id) {
    for (int i = 0; i < size; i++) {
        int py = y + i;
        if (x < BOARD_SIZE_X && py < BOARD_SIZE_Y)
            board[py][x] = id;
    }
}

// Navio diagonal principal (↘)
void drawDiagonalShip(int board[BOARD_SIZE_Y][BOARD_SIZE_X], int x, int y, int size, int id) {
    for (int i = 0; i < size; i++) {
        int px = x + i;
        int py = y + i;
        if (px < BOARD_SIZE_X && py < BOARD_SIZE_Y)
            board[py][px] = id;
    }
}

// Navio diagonal invertida (↙)
void drawInvertedDiagonalShip(int board[BOARD_SIZE_Y][BOARD_SIZE_X], int x, int y, int size, int id) {
    for (int i = 0; i < size; i++) {
        int px = x - i;
        int py = y + i;
        if (px >= 0 && py < BOARD_SIZE_Y)
            board[py][px] = id;
    }
}

// =======================================================
// Funções de desenho de ataques
// =======================================================

// Ataque tipo 1: CONE
// Forma:
//   0 0 3 0 0
//   0 3 3 3 0
//   3 3 3 3 3
void drawAttack1(int board[BOARD_SIZE_Y][BOARD_SIZE_X], int centerX, int centerY) {
    // Topo
    if (centerY - 2 >= 0 && centerX >= 0 && centerX < BOARD_SIZE_X)
        board[centerY - 2][centerX] = 3;

    // Meio
    for (int dx = -1; dx <= 1; dx++) {
        int x = centerX + dx;
        int y = centerY - 1;
        if (x >= 0 && x < BOARD_SIZE_X && y >= 0)
            board[y][x] = 3;
    }

    // Base
    for (int dx = -2; dx <= 2; dx++) {
        int x = centerX + dx;
        int y = centerY;
        if (x >= 0 && x < BOARD_SIZE_X && y >= 0 && y < BOARD_SIZE_Y)
            board[y][x] = 3;
    }
}

// Ataque tipo 2: CRUZ
// Forma:
//   0 0 3 0 0
//   3 3 3 3 3
//   0 0 3 0 0
void drawAttack2(int board[BOARD_SIZE_Y][BOARD_SIZE_X], int centerX, int centerY) {
    // Linha horizontal
    for (int dx = -2; dx <= 2; dx++) {
        int x = centerX + dx;
        if (x >= 0 && x < BOARD_SIZE_X)
            board[centerY][x] = 3;
    }

    // Linha vertical
    for (int dy = -1; dy <= 1; dy++) {
        int y = centerY + dy;
        if (y >= 0 && y < BOARD_SIZE_Y)
            board[y][centerX] = 3;
    }
}

// Ataque tipo 3: OCTAEDRO
// Forma:
//   0 3 0
//   3 3 3
//   0 3 0
void drawAttack3(int board[BOARD_SIZE_Y][BOARD_SIZE_X], int centerX, int centerY) {
    // Superior
    if (centerY - 1 >= 0)
        board[centerY - 1][centerX] = 3;

    // Linha central
    for (int dx = -1; dx <= 1; dx++) {
        int x = centerX + dx;
        if (x >= 0 && x < BOARD_SIZE_X && centerY >= 0 && centerY < BOARD_SIZE_Y)
            board[centerY][x] = 3;
    }

    // Inferior
    if (centerY + 1 < BOARD_SIZE_Y)
        board[centerY + 1][centerX] = 3;
}

// =======================================================
// Função para imprimir o tabuleiro
// =======================================================
void printBoard(int board[BOARD_SIZE_Y][BOARD_SIZE_X]) {
    printf("=== TABULEIRO ===\n");
    printf("    A   B   C   D   E   F   G   H   I   J\n");
    for (int y = 0; y < BOARD_SIZE_Y; y++) {
        printf("%2d  ", y + 1);
        for (int x = 0; x < BOARD_SIZE_X; x++)
            printf("%d   ", board[y][x]);
        printf("\n");
    }
}

// =======================================================
// Função principal
// =======================================================
int main() {
    int board[BOARD_SIZE_Y][BOARD_SIZE_X] = {0};

    // Exemplo: desenhar navios (IDs 1–4)
    /*
    drawVerticalShip(board, 2, 3, 3, 1);         // ↓
    drawHorizontalShip(board, 6, 1, 3, 2);       // →
    drawDiagonalShip(board, 0, 0, 4, 3);         // ↘
    drawInvertedDiagonalShip(board, 9, 0, 3, 4); // ↙
    */

    // Exemplo: desenhar ataques
    drawAttack1(board, 2, 2); // Cone
    drawAttack2(board, 7, 3); // Cruz
    drawAttack3(board, 2, 8); // Octaedro
    
    printBoard(board);
    return 0;
}