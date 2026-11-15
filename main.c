
#include <stdio.h>
#include "tic-tac-toe.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
srand(time(NULL));

    char board[9];
    int game_over = 0;

    init_board(board);

    printf("\n========================\n");
    printf("    BIENVENUE AU MORPION\n");
    printf("========================\n");

    printf("\nTu joues avec X.\n");
    printf("L'ordinateur joue avec O.\n");

    while (game_over == 0)
    {
        display_board(board);

        // Tour du joueur
        if (player_turn(board) == 0)
        {
            printf("\nFin de la saisie.\n");
            break;
        }

        // Vérification victoire joueur
        if (check_win(board, 'X'))
        {
            display_board(board);
            printf("BRAVO ! TU AS GAGNE !\n");
            game_over = 1;
            continue;
        }

        // Vérification match nul
        if (check_draw(board))
        {
            display_board(board);
            printf("MATCH NUL !\n");
            game_over = 1;
            continue;
        }

        // Tour ordinateur
        computer_turn(board);

        // Vérification victoire ordinateur
        if (check_win(board, 'O'))
        {
            display_board(board);
            printf("L'ORDINATEUR A GAGNE !\n");
            game_over = 1;
            continue;
        }

        // Vérification match nul
        if (check_draw(board))
        {
            display_board(board);
            printf("MATCH NUL !\n");
            game_over = 1;
        }
    }

    return 0;
}

