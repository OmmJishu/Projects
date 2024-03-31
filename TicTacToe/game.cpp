#include "game.h"

#include<bits/stdc++.h>
using namespace std;

Game::Game(const string& player1name, const string& player2name, int boardSize) : player1(player1name,'X'), player2(player2name,'O'), board(boardSize), currPlayer(&player1), isGameOver(false) {}

void Game::start(){
    cout<<"WELCOME TO THE GAME \n";
    board.display();

    while(!isGameOver){
        playTurn();
        board.display();
        if(board.checkWin(currPlayer->getSymbol())){
            cout<<currPlayer->getName()<<" Wins !!"<<endl;
            isGameOver = true;
        }
        else if(board.isFull()){
            cout<<"Its a DRAW Game !";
            isGameOver = true;
        }
        else{
            currPlayer = (currPlayer == &player1) ? &player2 : &player1;
        }
    }
}


void Game::playTurn(){
    int ro,col;
    cout<<"\n"<<currPlayer->getName()<<"`s Turn.  Enter row and Column (0 based indexing)  ";
    cin>>ro>>col;

    while(!board.placeMove(ro,col,currPlayer->getSymbol())){
        cout<<"Invalid Move. Try Again : ";
        cin>>ro>>col;

    }
}


bool Game::isDraw(){
    return board.isFull() && !board.checkWin(player1.getSymbol()) && !board.checkWin(player2.getSymbol());
}