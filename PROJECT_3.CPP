#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Function to get valid player move
void getPlayerMove(vector<vector<char>>& board, char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter your move (row and column 1-3): ";
        cin >> row >> col;
        
        // Check for valid input
        if (cin.fail() || row < 1 || row > 3 || col < 1 || col > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter numbers between 1 and 3.\n";
            continue;
        }
        
        // Convert to 0-based index
        row--;
        col--;
        
        // Check if cell is empty
        if (board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "That cell is already occupied! Try again.\n";
        }
    }
}

int main() {
    char playAgain;
    
    do {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;
        
        cout << "\n=== TIC-TAC-TOE ===\n";
        cout << "Player 1: X\nPlayer 2: O\n";
        
        while (!gameWon && !gameDraw) {
            displayBoard(board);
            getPlayerMove(board, currentPlayer);
            
            // Check for win
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
            } 
            // Check for draw
            else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!\n";
                gameDraw = true;
            } 
            // Switch players
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        
    } while (tolower(playAgain) == 'y');
    
    cout << "\nThanks for playing Tic-Tac-Toe!\n";
    return 0;
}