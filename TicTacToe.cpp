#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> // für system("cls") bzw. system("clear")

//Buchstaben fürs Spiel
const char spieler = 'X';
const char ai = 'O';
const char leer = ' ';

class TicTacToe {
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')) {} //Deklartion fürs board

    void printBoard()
    {
        for (int reihe = 0; reihe < 3; reihe++)
        {
            for (int zeile = 0; zeile < 3; zeile++)
            {
                std::cout << board[reihe][zeile];
                if (zeile < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (reihe < 2) std::cout << "----------" << std::endl;
        }
    }

    bool spielerMove(int reihe, int zeile, char character)
    {
        reihe--; // Konvertiere 1-basierte Eingabe in 0-basierten Index
        zeile--; // Konvertiere 1-basierte Eingabe in 0-basierten Index

        if (reihe < 0 || reihe > 2 || zeile < 0 || zeile > 2 || board[reihe][zeile] != ' ')
        {
            std::cout << " Fehler: Ungültiger Zug " << "\n";
            return false;
        }

        board[reihe][zeile] = character;
        return true;
    }

    bool isMovesLeft()
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == leer)
                    return true;
        return false;
    }

    char checkWin()
    {
        // Überprüfen auf Reihen, Spalten und Diagonalen
        for (int reihe = 0; reihe < 3; ++reihe) {
            if (board[reihe][0] == board[reihe][1] && board[reihe][1] == board[reihe][2] && board[reihe][0] != leer) {
                return board[reihe][0];
            }
        }

        for (int zeile = 0; zeile < 3; ++zeile) {
            if (board[0][zeile] == board[1][zeile] && board[1][zeile] == board[2][zeile] && board[0][zeile] != leer) {
                return board[0][zeile];
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != leer) { //diagonal
            return board[0][0];
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != leer) {
            return board[0][2];
        }

        return leer;
    }

    void resetBoard() //zurücksetzen nach einem Spiel
    {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    }

    int minimax(bool isMax) //https://de.wikipedia.org/wiki/Minimax-Algorithmus
    {
        char winner = checkWin();
        if (winner == ai) return 10;
        if (winner == spieler) return -10;
        if (!isMovesLeft()) return 0;

        if (isMax)
        {
            int best = std::numeric_limits<int>::min();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == leer)
                    {
                        board[i][j] = ai;
                        best = std::max(best, minimax(false));
                        board[i][j] = leer;
                    }
                }
            }
            return best;
        }
        else
        {
            int best = std::numeric_limits<int>::max();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == leer)
                    {
                        board[i][j] = spieler;
                        best = std::min(best, minimax(true));
                        board[i][j] = leer;
                    }
                }
            }
            return best;
        }
    }

    std::pair<int, int> findBestMove()
    {
        int bestVal = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove = { -1, -1 };

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == leer)
                {
                    board[i][j] = ai;
                    int moveVal = minimax(false);
                    board[i][j] = leer;

                    if (moveVal > bestVal)
                    {
                        bestMove.first = i;
                        bestMove.second = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        return bestMove;
    }

private:
    std::vector<std::vector<char>> board;
};


//Console clear damit immer nur das aktuelle Board angezeigt wird
void clearScreen() {
//windows
#ifdef _WIN32
    std::system("cls");
//Unix?
#else
    std::system("clear");
#endif
}

bool wantToPlay() {
    char choice;
    std::cout << "Möchten Sie ein Spiel Tic-Tac-Toe spielen? (j/n): ";
    std::cin >> choice;
    return choice == 'j' || choice == 'J';
}

bool playAgainstAI() {
    char choice;
    std::cout << "Möchten Sie gegen die KI spielen? (j/n): ";
    std::cin >> choice;
    return choice == 'j' || choice == 'J';
}

int main() {
    TicTacToe game;

    while (true) {
        if (!wantToPlay()) {
            break;
        }

        bool gegenAI = playAgainstAI();
        char currentPlayer = spieler;
        game.resetBoard();

        while (true) {
            clearScreen();
            game.printBoard();

            if (currentPlayer == spieler || !gegenAI) {
                int reihe, zeile;
                std::cout << "Spieler " << currentPlayer << ", geben Sie Ihre Zugzeile und -spalte ein (1-3): ";
                std::cin >> reihe >> zeile;

                if (game.spielerMove(reihe, zeile, currentPlayer)) {
                    char winner = game.checkWin();
                    if (winner != leer) {
                        clearScreen();
                        game.printBoard();
                        std::cout << "Spieler " << winner << " hat gewonnen!\n";
                        break;
                    }
                    else if (!game.isMovesLeft()) {
                        clearScreen();
                        game.printBoard();
                        std::cout << "Unentschieden!\n";
                        break;
                    }
                    currentPlayer = (currentPlayer == spieler) ? ai : spieler;
                }
                else {
                    std::cout << "Ungültiger Zug. Bitte erneut versuchen.\n";
                }
            }
            else {
                std::pair<int, int> bestMove = game.findBestMove();
                game.spielerMove(bestMove.first + 1, bestMove.second + 1, ai);

                char winner = game.checkWin();
                if (winner != leer) {
                    clearScreen();
                    game.printBoard();
                    std::cout << "Spieler " << winner << " hat gewonnen!\n";
                    break;
                }
                else if (!game.isMovesLeft()) {
                    clearScreen();
                    game.printBoard();
                    std::cout << "Unentschieden!\n";
                    break;
                }
                currentPlayer = spieler;
            }
        }
    }

    std::cout << "Vielen Dank fürs Spielen!\n";
    return 0;
}