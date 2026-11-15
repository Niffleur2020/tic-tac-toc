
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

void init_board(char board[9]);
void display_board(char board[9]);
int player_turn(char board[9]);
void computer_turn(char board[9]);
int check_win(char board[9], char symbol);
int check_draw(char board[9]);

#endif

