#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, EMPTY));
        currentPlayer = PLAYER_X; // X starts first
    }

    void displayBoard() {
        cout << "Current Board:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool isBoardFull() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == EMPTY) return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    void playSinglePlayer() {
        while (true) {
            displayBoard();
            int row, col;

            // Player's turn
            cout << "Enter your move (row and column): ";
            cin >> row >> col;

            if (!makeMove(row - 1, col - 1)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            // Computer's turn
            srand(time(0));
            do {
                row = rand() % 3;
                col = rand() % 3;
            } while (!makeMove(row, col));

            if (checkWin()) {
                displayBoard();
                cout << "Computer (" << PLAYER_O << ") wins!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }
        }
    }

    void playTwoPlayers() {
        while (true) {
            displayBoard();
            int row, col;

            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (!makeMove(row - 1, col - 1)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    int mode;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Select mode:\n1. Single Player\n2. Two Players\n";
    cin >> mode;

    if (mode == 1) {
        game.playSinglePlayer();
    } else if (mode == 2) {
        game.playTwoPlayers();
    } else {
        cout << "Invalid mode selected.\n";
    }

    return 0;
}