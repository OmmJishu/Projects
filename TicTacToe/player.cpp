#include<bits/stdc++.h>
#include "player.h"
using namespace std;

Player::Player(const string &name, char symb){
    this->name = name;
    symbol = symb;
}

string Player::getName(){
    return name;
}

char Player::getSymbol(){
    return symbol;
}