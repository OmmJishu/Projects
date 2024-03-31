#include<bits/stdc++.h>
#include "game.h"
using namespace std;

int main(){

    int boardSize;
    string player1Name, player2Name;

    cout<<"Enter Board size : ";
    cin>>boardSize;
    
    cout<<"Enter Player1 Name : ";
    cin>>player1Name;
    cout<<"Enter Player2 Name : ";
    cin>>player2Name;
    

    Game TicTacToe(player1Name, player2Name, boardSize);

    TicTacToe.start();
    return 0;
}