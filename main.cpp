#include <iostream>
#include <string>

using namespace std;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Player names
string playerXName, playerOName;

// Current player (X or O)
char currentPlayer = 'X';

// Function to sign in players
void signIn(){
    cout << "Enter player X name: ";
    cin >> playerXName;
    cout << "Enter player O name: ";
    cin >> playerOName;
}

// Function to print the game board+

// void printBoard(){
//     cout << endl;
//     cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
//     cout << "-----------------" << endl;
//     cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
//     cout << "-----------------" << endl;
//     cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
//     cout << endl;
// }





// Function to print the game board
void printBoard(){
    cout << endl;
    cout << "  ";
    if(board[0] == 'X') { cout << "\033[31m" << board[0] << "\033[0m"; } // X is red
    else if(board[0] == 'O') { cout << "\033[32m" << board[0] << "\033[0m"; } // O is green
    else { cout << board[0]; }
    cout << "  |  ";
    if(board[1] == 'X') { cout << "\033[31m" << board[1] << "\033[0m"; }
    else if(board[1] == 'O') { cout << "\033[32m" << board[1] << "\033[0m"; }
    else { cout << board[1]; }
    cout << "  |  ";
    if(board[2] == 'X') { cout << "\033[31m" << board[2] << "\033[0m"; }
    else if(board[2] == 'O') { cout << "\033[32m" << board[2] << "\033[0m"; }
    else { cout << board[2]; }
    cout << endl;
    cout << "-----------------" << endl;
    cout << "  ";
    if(board[3] == 'X') { cout << "\033[31m" << board[3] << "\033[0m"; }
    else if(board[3] == 'O') { cout << "\033[32m" << board[3] << "\033[0m"; }
    else { cout << board[3]; }
    cout << "  |  ";
    if(board[4] == 'X') { cout << "\033[31m" << board[4] << "\033[0m"; }
    else if(board[4] == 'O') { cout << "\033[32m" << board[4] << "\033[0m"; }
    else { cout << board[4]; }
    cout << "  |  ";
    if(board[5] == 'X') { cout << "\033[31m" << board[5] << "\033[0m"; }
    else if(board[5] == 'O') { cout << "\033[32m" << board[5] << "\033[0m"; }
    else { cout << board[5]; }
    cout << endl;
    cout << "-----------------" << endl;
    cout << "  ";
    if(board[6] == 'X') { cout << "\033[31m" << board[6] << "\033[0m"; }
    else if(board[6] == 'O') { cout << "\033[32m" << board[6] << "\033[0m"; }
    else { cout << board[6]; }
    cout << "  |  ";
    if(board[7] == 'X') { cout << "\033[31m" << board[6] << "\033[0m"; }
    else if(board[7] == 'O') { cout << "\033[32m" << board[6] << "\033[0m"; }
    else { cout << board[7]; }
    cout << "  |  ";
    if(board[8] == 'X') { cout << "\033[31m" << board[6] << "\033[0m"; }
    else if(board[8] == 'O') { cout << "\033[32m" << board[6] << "\033[0m"; }
    else { cout << board[8]; }
    cout << endl;
}


// Function to check if there is a winner
char winnerCheck() {
    if (board[0] == board[1] && board[1] == board[2]) { return board[0]; }
    else if (board[3] == board[4] && board[4] == board[5]) { return board[3]; }
    else if (board[6] == board[7] && board[7] == board[8]) { return board[6]; }

    // vertical wins
    if (board[0] == board[3] && board[3] == board[6]) { return board[0]; }
    else if (board[1] == board[4] && board[4] == board[7]) { return board[1]; }
    else if (board[2] == board[5] && board[5] == board[8]) { return board[2]; }

    // diagonal wins
    if (board[0] == board[4] && board[4] == board[8]) { return board[0]; }
    else if (board[2] == board[4] && board[4] == board[6]) { return board[2]; }

    return ' ';
}

// Function to check if a space on the board is available
bool isSpaceAvailable(int index){
    if (board[index - 1] != 'X' && board[index - 1] != 'O') {
        return true;
    } else { return false; }
}



// // Function to switch the current player
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}


void askForMove(char playerTurn) {
    cout<<"its "<< playerTurn << " Turn, Enter your move: ";
}



int main() {
    signIn();

    bool gameOver = false;
    int move;
    int turns = 0;

    while (!gameOver) {
        printBoard();
        while (true) {
            askForMove(currentPlayer);
            cin>> move;
            if (isSpaceAvailable(move)) {
                board[move - 1] = currentPlayer;
                turns++;
                switchPlayer();
                printBoard();
            } else {
                cout << "\nThat place is already marked. Please choose another place." << endl;
            }
            char winner = winnerCheck();
            if (winner == 'X') {
                cout << "\nCongratulations " << playerXName << ", you won!" << endl;
                gameOver = true;
                break;
            } else if (winner == 'O') {
                cout << "\nCongratulations " << playerOName << ", you won!" << endl;
                gameOver = true;
                break;
            } else if (turns == 9) {
                cout << "\nThe game is a tie!" << endl;
                gameOver = true;
                break;
            }
        }
    }
    return 0;
}