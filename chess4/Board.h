#pragma once
class Board
{
private: 
    vector <vector<int>> board;

public:
    Board();
    

    void move(string posit, string step);
    set<vector<int>> under_attack( int );
    vector<vector<vector<int>>> general_poss_st( int );
    vector<vector<int>> pawnposs(int x, int y, int color);
    vector<vector<int>> rookposs(int x, int y);
    vector<vector<int>> knightposs(int x, int y);
    vector<vector<int>> bishopposs(int x, int y);
    vector<vector<int>> queenposs(int x, int y);
    vector<vector<int>> kingposs(int x, int y, int color);
    bool  check(set<vector<int>> vec, int color);
    bool inadmissible_step(vector<vector<int>>, int);
    vector<vector<int>> getBoard();

    vector<vector<int>> pawnattack(int x, int y, int color);
    vector<vector<int>> rookattack(int x, int y);
    vector<vector<int>> knightattack(int x, int y);
    vector<vector<int>> bishopattack(int x, int y);
    vector<vector<int>> queenattack(int x, int y);
    vector<vector<int>> kingattack(int x, int y);
    
};

