//Reese Edens 

#include <iostream>
#include <stdlib.h>
#include <windows.h>
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
//starting array for the board 
char ticTacBoard[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
//Variables used
int choice;
int row, column;
char turn = 'X';
bool draw = false;
//this will show the current board
void show_board() {
    SetConsoleTextAttribute(h, 9);
    cout << "PLAYER - 1 [X]\n";
    SetConsoleTextAttribute(h, 4);
    cout << "PLAYER - 2 [O]\n";
    SetConsoleTextAttribute(h, 7);
    cout << "     |     |     \n";
    cout << "  " << ticTacBoard[0][0] << "  |  " << ticTacBoard[0][1] << "  |  " << ticTacBoard[0][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << ticTacBoard[1][0] << "  |  " << ticTacBoard[1][1] << "  |  " << ticTacBoard[1][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << ticTacBoard[2][0] << "  |  " << ticTacBoard[2][1] << "  |  " << ticTacBoard[2][2] << " \n";
    cout << "     |     |     \n";
}
void player_turn() {
    if (turn == 'X') {
        SetConsoleTextAttribute(h, 9);
        cout << "Player - 1 [X] turn: ";
    }
    else if (turn == 'O') {
        SetConsoleTextAttribute(h, 4);
        cout << "Player - 2 [O] turn: ";
    }
    //this is where you recieve the user number and the board changes with input
    cin >> choice;
    //switch changes the row and column
    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
    }
    if (turn == 'X' && ticTacBoard[row][column] != 'X' && ticTacBoard[row][column] != 'O') {
        //the position for 'X' if not in use
        ticTacBoard[row][column] = 'X';
        turn = 'O';
        SetConsoleTextAttribute(h, 9);
    }
    else if (turn == 'O' && ticTacBoard[row][column] != 'X' && ticTacBoard[row][column] != 'O') {
        //the position for 'O' symbol if not in use
        ticTacBoard[row][column] = 'O';
        turn = 'X';
    }
    else {
        //if input position already filled
        cout << "This number has been picked already!!\n Please choose another!!\n";
        player_turn();
    }
    /* Ends */
    show_board();
}
bool gameoverCheck() {
    //checking the win 
    for (int i = 0; i < 3; i++)
        if (ticTacBoard[i][0] == ticTacBoard[i][1] && ticTacBoard[i][0] == ticTacBoard[i][2] || ticTacBoard[0][i] == ticTacBoard[1][i] && ticTacBoard[0][i] == ticTacBoard[2][i])
            return false;
    //checking the diagonal
    if (ticTacBoard[0][0] == ticTacBoard[1][1] && ticTacBoard[0][0] == ticTacBoard[2][2] || ticTacBoard[0][2] == ticTacBoard[1][1] && ticTacBoard[0][2] == ticTacBoard[2][0])
        return false;
    //Checking continue or not
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (ticTacBoard[i][j] != 'O' && ticTacBoard[i][j] != 'X')
                return true;
    //Checking draw
    draw = true;
    return false;
}
int main()
{
    while (gameoverCheck()) {
        show_board();
        player_turn();
        gameoverCheck();
    }
    if (turn == 'X' && draw == false) {
        cout << "\n ^(-.-)> Player One is the CHAMP! <(-.-)^";
    }
    else if (turn == 'O' && draw == false) {
        cout << "\n ^(-.-)> Player Two is the CHAMP! <(-.-)^";
    }
    else
        cout << "\n ^(-.-)> Tie Game <(-.-)^"; 
}
