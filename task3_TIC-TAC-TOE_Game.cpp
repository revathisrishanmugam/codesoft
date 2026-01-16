#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void displayBoard() {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "---+---+---" << endl;
    }
    cout << endl;
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer &&
           board[i][1] == currentPlayer &&
           board[i][2] == currentPlayer)
            return true;

        if(board[0][i] == currentPlayer &&
           board[1][i] == currentPlayer &&
           board[2][i] == currentPlayer)
            return true;
    }

    if(board[0][0] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][2] == currentPlayer)
        return true;

    if(board[0][2] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][0] == currentPlayer)
        return true;

    return false;
}

bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int choice;
    bool gameOver = false;

    cout << "TIC TAC TOE GAME" << endl;

    while(!gameOver) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;

            if(checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            }
            else if(checkDraw()) {
                displayBoard();
                cout << "Game Draw!" << endl;
                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }
        else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    return 0;
}