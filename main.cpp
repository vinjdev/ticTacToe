#include <cstdlib> // system("cls")
#include <iostream> // cin og cout

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
    for (int i = 0; i < tiles; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || // check row
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))   // check col
            return true;
    } 
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
            return true;

    return false;
}

bool checkTie() {
    for (int row = 0; row < tiles; row++) {
        for (int col = 0; col < tiles; col++) {
            if (board[row][col] != 'X' && board[row][col] != 'O')
                return false; 
        }
    }
    return true;
}

int main(void) {
    bool gameWon = false; 
    bool gameTie = false;
    while (!gameWon && !gameTie) {
        printBoard();
        playerUpdate();
        gameWon = checkWin(); 
        gameTie = checkTie();
    }

    if (gameTie) {
        printBoard();
        std::cout << "Game Tie!!\n";
    }
    else if (gameWon){
        playerSwitch(); // switch back, siden ikke kjører funksjonen igjen etter loop
        printBoard();
        std::cout << "player: " << current << " won\n";
    }
    
    return 0;
}
