#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() : board(3, vector<char>(3, ' ')) {}

    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j];
                if (j < 2) cout << "|";
            }
            std::cout << endl;
            if (i < 2) std::cout << "-----" << endl;
        }
    }

private:
    vector<vector<char>> board;
};

int main() {
    TicTacToe game;
    game.printBoard();
    return 0;
}
