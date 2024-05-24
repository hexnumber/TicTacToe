# Tic-Tac-Toe Game

Ein einfaches Tic-Tac-Toe Spiel in C++, das sowohl gegen einen menschlichen Gegner als auch gegen eine KI gespielt werden kann. Die KI verwendet den Minimax-Algorithmus.

## Funktionsweise

- Das Spiel wird im Terminal ausgeführt.
- Der Spieler kann wählen, ob er gegen einen anderen Spieler oder gegen die KI spielen möchte.
- Die Spielfeldgröße beträgt 3x3.
- Die Spieler machen abwechselnd ihre Züge, bis ein Spieler gewinnt oder das Spiel unentschieden endet.

## Voraussetzungen

- Ein C++ Compiler (z.B. g++).

## Kompilieren und Ausführen

1. Klone das Repository:
    ```sh
    git clone https://github.com/hexnumber/TicTacToe.git
    cd tic-tac-toe
    ```

2. Kompiliere das Programm:
    ```sh
    g++ -o tic_tac_toe main.cpp
    ```

3. Führe das Programm aus:
    ```sh
    ./tic_tac_toe
    ```

## Spielanleitung

1. Beim Start des Spiels wirst du gefragt, ob du spielen möchtest. Gib `j` für Ja oder `n` für Nein ein.
2. Wenn du spielen möchtest, wirst du gefragt, ob du gegen die KI spielen möchtest. Gib `j` für Ja oder `n` für Nein ein.
3. Gib die Zeile und Spalte (1-3) für deinen Zug ein, wenn du an der Reihe bist.
4. Das Spielfeld wird nach jedem Zug aktualisiert und angezeigt.
5. Das Spiel endet, wenn ein Spieler gewinnt oder das Spielfeld voll ist.
6. Nach dem Spiel kannst du wählen, ob du ein weiteres Spiel spielen möchtest.

## Implementierungsdetails

- Das Programm verwendet eine einfache Terminal-Benutzeroberfläche.
- Die KI verwendet den Minimax-Algorithmus, um den besten Zug zu berechnen.
- Das Spielfeld wird nach jedem Zug aktualisiert, um den aktuellen Spielstand anzuzeigen.

## Autoren

- Julian Seipp / Hexnumber
