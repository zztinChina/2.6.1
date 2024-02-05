#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define BOARD_SIZE 15  
#define WIN_LENGTH 5  

char board[BOARD_SIZE][BOARD_SIZE];

int isWin(int x, int y, char player) {
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; i++) {
        int count = 1;
        for (int j = 1; j < WIN_LENGTH; j++) {
            int nx = x + j * dx[i];
            int ny = y + j * dy[i];
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player) {
                count++;
            }
            else {
                break;
            }
        }
        for (int j = 1; j < WIN_LENGTH; j++) {
            int nx = x - j * dx[i];
            int ny = y - j * dy[i];
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player) {
                count++;
            }
            else {
                break;
            }
        }
        if (count >= WIN_LENGTH) {
            return 1;
        }
    }
    return 0;
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    memset(board, '.', sizeof(board));
    char player = 'X';
    int x, y;

    while (1) {
        printBoard();
        printf("Player %c, enter your move (row column): ", player);
        scanf_s("%d %d", &x, &y);

        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || board[x][y] != '.') {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[x][y] = player;

        if (isWin(x, y, player)) {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}