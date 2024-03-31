#include<bits/stdc++.h>

#ifndef Game_H
#define game_H
#include "board.h"
#include "player.h"
using namespace std;


class Game{
    private:
        Board board;
        Player player1;
        Player player2;
        Player* currPlayer;
        bool isGameOver;

    public:
        Game(const string& player1, const string& player2, int boardSize);
        void start();
        void playTurn();
        bool isDraw();
};

#endif