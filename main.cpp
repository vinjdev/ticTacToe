#include <cstdlib>
#include <iostream>

const int tiles = 3;
char board[tiles][tiles] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
char current = 'X';

void printBoard() {
    system("clear");
    std::cout << "Tic Tac Toe\n";
    for (int row = 0; row < tiles; row++) {
        for (int col = 0; col < tiles; col++) {
            std::cout << board[row][col];
            if (col < tiles - 1) std::cout << " | ";
        }
        std::cout << "\n"; 
        if (row < tiles -1) std::cout << "--|---|--\n";
    }
}

void playerSwitch() {
    current = (current == 'X' ? 'O' : 'X');
}

void playerUpdate() {
    int move;
    std::cout << "Current player: " << current << "\n";
    std::cin >> move;

    int row,col;
    row = (move - 1) / tiles;
    col = (move - 1) % tiles;

    if (board[row][col] != 'X' && board[row][col] != 'O' && move > 0 && move < 10) {
        board[row][col] = current;
        playerSwitch();
    }
    else {
        printBoard();
        std::cout << "Invalid placement, try again..\n";
        playerUpdate();
    }
}

bool checkWin() {
    char p1 = 'X';
    char p2 = 'O';
    for (int row = 0; row < tiles; row++) {
        if (board[row][0] == p1 && board[row][1] == p1 && board[row][2] == p1)
            return true;
        if (board[row][0] == p2 && board[row][1] == p2 && board[row][2] == p2)
            return true;
    }
    for (int col = 0; col < tiles; col++) {
        if (board[0][col] == p1 && board[1][col] == p1 && board[2][col] == p1)
            return true;
        if (board[0][col] == p2 && board[1][col] == p2 && board[2][col] == p2)
            return true;
    }



    return false;
}

int main(void) {
    bool gameOver = false; 
    while (!gameOver) {
        printBoard();
        playerUpdate();
        if (checkWin()) {
            gameOver = true;
        }
    }
    printBoard();
    std::cout << "player: " << current << " won\n";
    return 0;
}
