#include<bits/stdc++.h>
#ifndef Board_H
#define Board_H
using namespace std;

class Board{
    private:
        int size;
        vector<vector<char>> board;
    
    public:
        Board(int sz);
        void display();
        bool isFull();
        bool placeMove(int row, int col, char symbol);
        bool checkWin(char symbol);

};

#endif