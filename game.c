
#include <stdio.h>
#include "tic-tac-toe.h"

// Initialise le plateau
void init_board(char board[9])
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

// Affiche le plateau
void display_board(char board[9])
{
    printf("\n");

    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
            printf(" %d ", i);
        else
            printf(" %c ", board[i]);

        if (i % 3 != 2)
            printf("|");
        else if (i != 8)
            printf("\n-----------\n");
    }

    printf("\n\n");
}

// Tour du joueur
int player_turn(char board[9])
{
    int position;
    int result;

    while (1)
    {
        printf("Choisis une case (0-8) : ");
        result = scanf("%d", &position);

        if (result == EOF)
            return 0;

        if (result != 1)
        {
            int c;

            printf("Entre un nombre valide.\n");

            while ((c = getchar()) != '\n' && c != EOF)
            {
                ;
            }

            continue;
        }

        if (position < 0 || position > 8)
        {
            printf("Position invalide !\n");
            continue;
        }

        if (board[position] != ' ')
        {
            printf("Case deja occupee !\n");
            continue;
        }

        board[position] = 'X';
        return 1;
    }
}

// Tour de l'ordinateur
void computer_turn(char board[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'O';
            printf("L'ordinateur joue en position %d.\n", i);
            return;
        }
    }
}

// Vérification de victoire
int check_win(char board[9], char symbol)
{
    int combinations[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++)
    {
        if (board[combinations[i][0]] == symbol &&
            board[combinations[i][1]] == symbol &&
            board[combinations[i][2]] == symbol)
        {
            return 1;
        }
    }

    return 0;
}

// Vérification du match nul
int check_draw(char board[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            return 0;
        }
    }

    return 1;
}

