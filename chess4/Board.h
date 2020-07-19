#pragma once
class Board
{
private: 
    std::vector<std::vector<int>> board;
    
    std::vector<std::vector<int>> pawnattack(int, int, std::vector<std::vector<int>>, int);
    std::vector<std::vector<int>> rookattack(int, int, std::vector<std::vector<int>>);
    std::vector<std::vector<int>> knightattack(int, int, std::vector<std::vector<int>>);
    std::vector<std::vector<int>> bishopattack(int, int, std::vector<std::vector<int>>);
    std::vector<std::vector<int>> kingattack(int, int, std::vector<std::vector<int>>);
    std::vector<std::vector<int>> queenattack(int, int, std::vector<std::vector<int>>);


public:
    Board();
   
    void move(std::string posit, std::string step);
    std::set<std::vector<int>> under_attack( int );
    std::vector<std::vector<std::vector<int>>> general_poss_st( int );
    std::vector<std::vector<int>> pawnposs(int x, int y, int color);
    std::vector<std::vector<int>> rookposs(int x, int y);
    std::vector<std::vector<int>> knightposs(int x, int y);
    std::vector<std::vector<int>> bishopposs(int x, int y);
    std::vector<std::vector<int>> queenposs(int x, int y);
    std::vector<std::vector<int>> kingposs(int x, int y, int color);
    bool  check(std::set<std::vector<int>> vec, int color);
    bool inadmissible_step(std::vector<std::vector<int>>, int);
    std::vector<std::vector<int>> getBoard();

    std::vector<std::vector<int>> pawnattack(int x, int y, int color);
    std::vector<std::vector<int>> rookattack(int x, int y);
    std::vector<std::vector<int>> knightattack(int x, int y);
    std::vector<std::vector<int>> bishopattack(int x, int y);
    std::vector<std::vector<int>> queenattack(int x, int y);
    std::vector<std::vector<int>> kingattack(int x, int y);
    
};

