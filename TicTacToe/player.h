#ifndef Player_H
#define Player_H

#include<bits/stdc++.h>
using namespace std;

class Player{
    private:
        string name;
        char symbol;
    
    public:
        Player(const string &name, char symb);
        string getName();
        char getSymbol();
};

#endif