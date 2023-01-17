#include "Functions.h"

void runGame()
{
    char ctn = 'Y';
    while(ctn == 'Y'||ctn == 'y'){
        int player = 0;
        char currentplayer = 'X';
        char board[3][3];
        initBoard(board);
        while(checkForWinner(currentplayer, board) == false && checkForDraw(board) == false){
            if(player%2 == 1){
                currentplayer = 'O';}
            else{currentplayer = 'X';}
            cout << "Enter coordinate for " << currentplayer << ". Input should be X Y\n";
            int X;
            cin >> X;
            int Y;
            cin >> Y;
            placeAPiece(X,Y,currentplayer, board);
            displayBoard(board);
            player += 1;}
        if (checkForWinner(currentplayer, board)){
            cout <<currentplayer<<" Won\n";}
        if (checkForDraw(board)){
            cout <<"Draw\n";}
        cout<<"Do you want to play again?\n";
        cin >> ctn;
        if(ctn == 'N' || ctn == 'n'){
            cout<<"Done\n";}
    }
}

void initBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void placeAPiece(int x, int y, char piece, char board[3][3])
{
    board[x][y] = piece;
}

bool checkForWinner(char piece, char board[3][3])
{
    bool win = false;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == piece && board[i][1] == piece && board[i][2] == piece){
            win = true;}
        if (board[0][i] == piece && board[1][i] == piece && board[2][i] == piece){
            win = true;}
    }
    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece){
        win = true;}
    if (board[0][2] == piece && board[1][1] == piece && board[2][0] == piece){
        win = true;}
    return win;
}

bool checkForDraw(char board[3][3])
{
    bool draw = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-'){
                draw = false;}
        }
    }
    return draw;


}


void displayBoard(char board[3][3])
{
    cout << board[0][0] << "|" << board[0][1] << '|' << board[0][2] << endl;
    cout << "-----\n" ;
    cout << board[1][0] << "|" << board[1][1] << '|' << board[1][2] << endl;
    cout << "-----\n";
    cout << board[2][0] << "|" << board[2][1] << '|' << board[2][2] << endl;

}
