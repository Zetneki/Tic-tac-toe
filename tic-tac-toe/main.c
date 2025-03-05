#include <stdio.h>
#include "stdlib.h"
#include "conio.h"
#include "string.h"

void make_board(int board[3][3]);
void print(int board[3][3]);
void rounds(int board[3][3], int *player, int *end);
int win(int board[3][3]);
int restart();

int main() {

    int board[3][3];
    int *player = (int*)malloc(sizeof(int));

    int *end = (int*)malloc(sizeof(int));
    *end = 0;

    char enter;

    printf("Welcome to the TIC-TAC-TOE game!\n\n");
    printf("To be able to play properly you will have to type in the values of the rows and columns.\n");
    printf("The values have to be NUMBERS.\n\n");
    printf("Have fun!\n\n");
    printf("Press ENTER to start.\n");
    scanf("%c", &enter);
    system("cls");

    jump:

    *player = 1;
    make_board(board);

    print(board);
    while (win(board) == 0) {
        printf("\n%d. Player\n\n", *player);
        rounds(board, player, end);
        *player = *player % 2 == 1 ? 2 : 1;
        if (*end == 9) {
            printf("The board is full.\n");
            break;
        }
    }

    if (restart() == 1) {
        system("cls");
        goto jump;
    }


    free(player);
    free(end);
    getch();
    return 0;
}

void make_board(int board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 0;
        }
    }
}

void print(int board[3][3]) {
    printf("\n");
    printf("| %d | %d | %d |\n", board[0][0], board[0][1], board[0][2]);
    printf("|---|---|---|\n");
    printf("| %d | %d | %d |\n", board[1][0], board[1][1], board[1][2]);
    printf("|---|---|---|\n");
    printf("| %d | %d | %d |\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

void rounds(int board[3][3], int *player, int *end) {

    int row, col;

    printf("Row: ");
    scanf("%d", &row);

    printf("Column: ");
    scanf("%d", &col);

    row -= 1;
    col -= 1;

    if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == 0) {
        system("cls");
        (*end)++;
        board[row][col] = *player;
        print(board);
    } else {
        printf("Invalid numbers given. Try again.\n");
        getch();
        *player = *player % 2 == 1 ? 2 : 1;
        system("cls");
        print(board);
    }
}

int win(int board[3][3]) {

            //diognal 1
            if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1 || board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1 ||

            //horizontal 1
            board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1 || board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1 || board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1 ||

            //vertical 1
            board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1 || board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1 || board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) {

                printf("The first player is the winner!\n");
                return 1;
            }


            //diognal 2
            else if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2 || board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2 ||

            //horizontal 2
            board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2 || board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2 || board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2 ||

            //vertical 2
            board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2 || board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2 || board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2) {

                printf("The second player is the winner!\n");
                return 1;
            }

            return 0;
}

int restart() {

    printf("\nWould you like to play again? (yes/no)\n");
    char decide[4];
    scanf("%s", decide);

    if (strcmp(decide, "yes") == 0) {
        return 1;
    }

    return 0;
}
