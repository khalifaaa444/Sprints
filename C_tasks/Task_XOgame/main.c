#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void drawBoard(uint8_t *board);
void updateBoard (uint8_t *board, uint8_t position, uint8_t value);
uint8_t Board[9]={'1','2','3','4','5','6','7','8','9'};
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);
void setPlayerConfig(uint8_t *configArray);
char player_names[2][20];
uint8_t symm[3];
void loadAndUpdate(uint8_t playerNumber);
void getGameState(uint8_t *board, uint8_t *gameState);
uint8_t Game_mod=4;
int main()
{
    drawBoard(Board);
    setPlayerConfig(symm);
    int Turn=0;
    while(1)
    {
        loadAndUpdate(Turn+1);
        getGameState(Board, &Game_mod);
        if(Game_mod == 0)
        {
            printf("player %i winer!!! \n", Turn+1);
            break;
        }
        else if(Game_mod == 1)
        {
             printf("DRAW!!! \n");
             break;
        }
        Turn ^= 1;

    }



    return 0;
}

void drawBoard(uint8_t *board)
{
    printf("\n");
    printf(" . . . . . . . . . . . . .\n ") ;
    printf(".       .       .       .\n ");
    printf(".  %c    .   %c   .    %c  .\n " , board[0], board[1], board[2]);
    printf(". . . . . . . . . . . . .\n ");
    printf(".       .       .       .\n ");
    printf(".  %c    .   %c   .    %c  .\n " , board[3], board[4], board[5]);
    printf(". . . . . . . . . . . . .\n ");
    printf(".       .       .       .\n ");
    printf(".  %c    .   %c   .    %c  .\n " , board[6], board[7], board[8]);
    printf(".       .       .       .\n ");
    printf(". . . . . . . . . . . . .\n ");
}

void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{
    board[position-1] = value;
    drawBoard(board);
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)
{

    uint8_t SYMB,flag=0;
    if(playerNumber == 1)
    {
    //printf("../,,\n");
    scanf("%c",&SYMB);
    fflush(stdin);fflush(stdout);
    if((SYMB == 'X')||(SYMB == 'O'))
    {
        *symbol=SYMB;
        printf("Saved. ..\n");
    }

    else
    {
        printf("this Symbol is not true , Try again with 'X' OR 'O' : ");
        flag=1;
    }
    }

    else
    {
         scanf("%c",&SYMB);
         fflush(stdin);fflush(stdout);
         symbol--;
    if((SYMB == 'X')||(SYMB == 'O'))
    {
      //  *symbol=SYMB;
      if(SYMB == *symbol)
      {
          printf("sorry, this symbol %c was taken, choose other symbol : ",*symbol);
          flag = 1;
      }
      else
      {
          printf("saved ...\n");
          symbol++;
          *symbol=SYMB;
      }

    }

    else
    {
        printf("this Symbol is not true , Try again with 'X' OR 'O' : ");
        flag=1;
    }

    }





    return flag;


}

void setPlayerConfig(uint8_t *configArray)
{
    printf("hi player 1 ,choose your symbol 'X or 'O'  :  ");
   // printf("%p   :  ",configArray);
    int x = (1 , configArray);
    while(x)
    {
         x = getPlayerSymbol(1 , configArray);
    }
    configArray++;

    printf("hi player 2 ,choose your symbol 'X or 'O'  :  ");
    //printf("%p   :  ",configArray);
    x = getPlayerSymbol(2 , configArray);
    while(x)
    {
         x = getPlayerSymbol(2 , configArray);
    }


}



void loadAndUpdate(uint8_t playerNumber)
{
    uint8_t turn;
    printf("hi player number %i , choose your position : ",playerNumber);
    scanf("%i",&turn);

    updateBoard(Board,turn,symm[playerNumber-1]);

}


void getGameState(uint8_t *board, uint8_t *gameState)
{
    static count=0;
    if (count<8)
    {

        if     ((board[0]==board[1])&&(board[1]==board[2]))      {*gameState=0;}
        else if((board[3]==board[4])&&(board[4]==board[5])) {*gameState=0;}
        else if((board[6]==board[7])&&(board[7]==board[8])) {*gameState=0;}
        else if((board[0]==board[4])&&(board[4]==board[8])) {*gameState=0;}
        else if((board[2]==board[4])&&(board[4]==board[6])) {*gameState=0;}
        else if((board[0]==board[3])&&(board[3]==board[6])) {*gameState=0;}
        else if((board[1]==board[4])&&(board[4]==board[7])) {*gameState=0;}
        else if((board[2]==board[5])&&(board[5]==board[8])) {*gameState=0;}
        else                                                {*gameState=2;}

        count++;
    }
    else
    {
        *gameState=1;
    }


}
