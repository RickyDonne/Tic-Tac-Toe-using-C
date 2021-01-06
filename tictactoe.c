#include <stdio.h>
#include <stdlib.h>

char board[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int player, choice;

int winCondition(); //Checks condition for win.
void boardMark(char mark); //Marks the board with player's choice
void displayBoard(); //Displays the board

int main()
{
    int status;
    char mark;
    player = 1;

    do
    {
        displayBoard();

        if ((player % 2) == 0) //This condition ensures that player number is either 1 or 0
            player = 2;
        else
            player = 1;

        printf("Player %d: ", player);
        scanf("%d", &choice);

        if (player == 1)
            mark = 'X';
        else
            mark = 'O';

        boardMark(mark);
        status = winCondition();
        ++player;
    }
    while (status == -1);

    if (status == 1)
        printf("\n\a      Congratulations Player %d!\n\n", --player);
    else
        printf("\n\aGame Draw\n\n");

    return 0;
}

int winCondition()
{
/*************************
* Status when:
*    Win: 1
*    Draw: 0
*    Game in progress: -1
**************************/
    int status = -1;

    if (board[1] == board[2] && board[2] == board[3])
        status = 1;
    else if (board[4] == board[5] && board[5] == board[6])
        status = 1;
    else if (board[7] == board[8] && board[8] == board[9])
        status = 1;

    else if (board[1] == board[4] && board[4] == board[7])
        status = 1;
    else if (board[2] == board[5] && board[5] == board[8])
        status = 1;
    else if (board[3] == board[6] && board[6] == board[9])
        status = 1;

    else if (board[1] == board[5] && board[5] == board[9])
        status = 1;
    else if (board[3] == board[5] && board[5] == board[7])
        status = 1;

    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' &&
             board[4] != '4' && board[5] != '5' && board[6] != '6' &&
             board[7] != '7' && board[8] != '8' && board[9] != '9')
        status = 0; //Status = 0 if board is not empty
    else
        status = -1; //Status = -1 if game is not win/draw.

    return status;
}

void displayBoard()
{
    system ("clear");

    printf("\n\n\tTic Tac Toe Game\n\n");
    printf("Player 1 uses X -- Player 2 uses O \n\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("\t     |     |     \n\n");

}

void boardMark(char mark)
{
    if (choice == 1 && board[1] == '1')
        board[1] = mark;
    else if (choice == 2 && board[2] == '2')
        board[2] = mark;
    else if (choice == 3 && board[3] == '3')
        board[3] = mark;
    else if (choice == 4 && board[4] == '4')
        board[4] = mark;
    else if (choice == 5 && board[5] == '5')
        board[5] = mark;
    else if (choice == 6 && board[6] == '6')
        board[6] = mark;
    else if (choice == 7 && board[7] == '7')
        board[7] = mark;
    else if (choice == 8 && board[8] == '8')
        board[8] = mark;
    else if (choice == 9 && board[9] == '9')
        board[9] = mark;
    else //if choice is not anything in between 1 to 9 then display error
    {
        printf("******** Invalid Move! ********");
        --player;
        getchar();
    }
}
