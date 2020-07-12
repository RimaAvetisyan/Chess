#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "Board.h"
#include "utils.h"

using namespace std;
Board::Board(){
    board = { {-1,-2,-3,-4,-5,-3,-2,-1},
                                        {-6,-6,-6,-6,-6,-6,-6,-6},
                                        {0,0,0,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,0},
                                        {6,6,6,6,6,6,6,6},
                                        {1,2,3,4,5,3,2,1} };
}

vector<vector<int>> Board::getBoard() {
    return board;
}
set<vector<int>> Board::under_attack( int color) {
    set<vector<int>> gps;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == (color * 6)) {
                for (size_t k = 0; k < pawnattack(i + 1, j + 1, color).size(); k++) {
                    gps.insert({ pawnattack(i + 1, j + 1,color)[k] });
                }

            }
            if (board[i][j] == (color * 1)) {
                for (size_t k = 0; k < rookattack(i + 1, j + 1).size(); k++) {
                    gps.insert(rookattack(i + 1, j + 1)[k]);
                }
            }
            if (board[i][j] == (color * 2)) {
                for (size_t k = 0; k < (knightattack(i + 1, j + 1).size()); k++) {
                    gps.insert(knightattack(i + 1, j + 1)[k]);
                }
            }
            if (board[i][j] == (color * 3)) {
                for (size_t k = 0; k < (bishopattack(i + 1, j + 1).size()); k++) {
                    gps.insert(bishopattack(i + 1, j + 1)[k]);
                }
            }
            if (board[i][j] == (color * 4)) {
                for (size_t k = 0; k < (queenattack(i + 1, j + 1).size()); k++) {
                    gps.insert(queenattack(i + 1, j + 1)[k]);
                }
            }
            if (board[i][j] == (color * 5)) {
                for (size_t k = 0; k < (kingattack(i + 1, j + 1).size()); k++) {
                    gps.insert(kingattack(i + 1, j + 1)[k]);
                }
            }
        }
    }
    return gps;
}
vector<vector<int>> Board::pawnattack(int x, int y, int color) {
    vector <vector <int>> steps;
    if (color = 1) {
        if (x < 8 && y < 8 && board[x + 1][y + 1] >= 0) {
            steps.push_back({ x + 1,y + 1 });
        }
        if (x > 1 && y < 8 && board[x - 1][y + 1] >= 0) {
            steps.push_back({ x - 1,y + 1 });
        }
    }
    else {
        if (x < 8 && y >1 && board[x + 1][y - 1] <= 0) {
            steps.push_back({ x + 1,y - 1 });
        }
        if (x > 1 && y > 1 && board[x - 1][y - 1] <= 0) {
            steps.push_back({ x - 1,y - 1 });
        }
    }
    return steps;
}
vector<vector<int>> Board::rookattack(int x, int y) {
    vector <vector <int>> steps;
    while (x < 8) {
        if (board[x + 1][y] <= 0) {
            steps.push_back({ x + 1,y });
            break;
        }
        else {
            steps.push_back({ x + 1,y });
            x++;
        }
    }
    while (x > 1) {
        if (board[x - 1][y] <= 0) {
            steps.push_back({ x - 1,y });
            break;
        }
        else {
            steps.push_back({ x - 1,y });
            x--;
        }
    }
    while (y < 8) {
        if (board[x][y + 1] <= 0) {
            steps.push_back({ x,y + 1 });
            break;
        }
        else {
            steps.push_back({ x,y + 1 });
            y++;
        }
    }
    while (y > 1) {
        if (board[x][y - 1] <= 0) {
            steps.push_back({ x,y - 1 });
            break;
        }
        else {
            steps.push_back({ x,y - 1 });
            y--;
        }
    }
    return steps;
}
vector<vector<int>> Board::knightattack(int x, int y) {
    vector <vector <int>> steps;
    if (x > 2) {
        if (y < 8 && board[x - 2][y + 1] <= 0) {
            steps.push_back({ x - 2,y + 1 });
        }
        if (y > 1 && board[x - 2][y - 1] <= 0) {
            steps.push_back({ x - 2,y - 1 });
        }
    }
    if (y < 7) {
        if (x > 1 && board[x - 1][y + 2] <= 0) {
            steps.push_back({ x - 1,y + 2 });
        }
        if (x < 8 && board[x + 1][y + 2] <= 0) {
            steps.push_back({ x + 1,y + 2 });
        }
    }
    if (x < 7) {
        if (y < 8 && board[x + 2][y + 1] <= 0) {
            steps.push_back({ x + 2,y + 1 });
        }
        if (y > 1 && board[x + 2][y - 1] <= 0) {
            steps.push_back({ x + 2,y - 1 });
        }
    }
    if (y > 2) {
        if (x < 8 && board[x + 1][y - 2] <= 0) {
            steps.push_back({ x + 1,y - 2 });
        }
        if (x > 1 && board[x - 1][y - 2] <= 0) {
            steps.push_back({ x - 1,y - 2 });
        }
    }
    return steps;
}
vector<vector<int>> Board::bishopattack(int x, int y) {
    vector <vector <int>> steps;
    while (x < 8 && y < 8) {
        if (board[x + 1][y + 1] <= 0) {
            steps.push_back({ x + 1,y + 1 });
            break;
        }
        steps.push_back({ x + 1,y + 1 });
        x++;
        y++;
    }
    while (x < 8 && y>1) {
        if (board[x + 1][y - 1] <= 0) {
            steps.push_back({ x + 1,y - 1 });
            break;
        }
        steps.push_back({ x + 1,y - 1 });
        x++;
        y--;
    }
    while (x > 1 && y > 1) {
        if (board[x - 1][y - 1] <= 0) {
            steps.push_back({ x - 1,y - 1 });
            break;
        }
        steps.push_back({ x - 1,y - 1 });
        x--;
        y--;
    }
    while (x < 1 && y < 8) {
        if (board[x - 1][y + 1] <= 0) {
            steps.push_back({ x - 1,y + 1 });
            break;
        }
        steps.push_back({ x - 1,y + 1 });
        x--;
        y++;
    }
    return steps;

}
vector<vector<int>> Board::queenattack(int x, int y) {
    vector <vector <int>> steps;
    while (x < 8) {
        if (board[x + 1][y] <= 0) {
            steps.push_back({ x + 1,y });
            break;
        }
        else {
            steps.push_back({ x + 1,y });
            x++;
        }
    }
    while (x > 1) {
        if (board[x - 1][y] <= 0) {
            steps.push_back({ x - 1,y });
            break;
        }
        else {
            steps.push_back({ x - 1,y });
            x--;
        }
    }
    while (y < 8) {
        if (board[x][y + 1] <= 0) {
            steps.push_back({ x,y + 1 });
            break;
        }
        else {
            steps.push_back({ x,y + 1 });
            y++;
        }
    }
    while (y > 1) {
        if (board[x][y - 1] <= 0) {
            steps.push_back({ x,y - 1 });
            break;
        }
        else {
            steps.push_back({ x,y - 1 });
            y--;
        }
    }
    while (x < 8 && y < 8) {
        if (board[x + 1][y + 1] <= 0) {
            steps.push_back({ x + 1,y + 1 });
            break;
        }
        steps.push_back({ x + 1,y + 1 });
        x++;
        y++;
    }
    while (x < 8 && y>1) {
        if (board[x + 1][y - 1] <= 0) {
            steps.push_back({ x + 1,y - 1 });
            break;
        }
        steps.push_back({ x + 1,y - 1 });
        x++;
        y--;
    }
    while (x > 1 && y > 1) {
        if (board[x - 1][y - 1] <= 0) {
            steps.push_back({ x - 1,y - 1 });
            break;
        }
        steps.push_back({ x - 1,y - 1 });
        x--;
        y--;
    }
    while (x < 1 && y < 8) {
        if (board[x - 1][y + 1] <= 0) {
            steps.push_back({ x - 1,y + 1 });
            break;
        }
        steps.push_back({ x - 1,y + 1 });
        x--;
        y++;
    }
    return steps;

}
vector<vector<int>> Board::kingattack(int x, int y) {
    vector <vector <int>> steps;
    if (y < 8) {
        steps.push_back({ x, y + 1 });
        if (x < 8) {
            steps.push_back({ x + 1, y + 1 });
        }
    }
    if (x < 8) {
        steps.push_back({ x + 1, y });
        if (y > 1) {
            steps.push_back({ x + 1, y - 1 });
        }
    }
    if (y > 1) {
        steps.push_back({ x, y - 1 });
        if (x > 1) {
            steps.push_back({ x - 1, y - 1 });
        }
    }
    if (x > 1) {
        steps.push_back({ x - 1, y });
        if (y < 8) {
            steps.push_back({ x - 1, y + 1 });
        }
    }
    return steps;
}
vector<vector<vector<int>>> Board::general_poss_st( int color) {
    vector<vector<vector<int>>> gps;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == color * 6) {
                for (size_t k = 0; k < pawnposs(i + 1, j + 1, color).size(); k++) {
                    gps.push_back({ { i + 1,j + 1 },pawnposs(i + 1, j + 1, color)[k] });
                }

            }
            if (board[i][j] == color * 1) {
                for (size_t k = 0; k < rookposs(i + 1, j + 1).size(); k++) {
                    gps.push_back({ { i + 1,j + 1 },rookposs(i + 1, j + 1)[k] });
                }
            }
            if (board[i][j] == color * 2) {
                for (size_t k = 0; k < (knightposs(i + 1, j + 1).size()); k++) {
                    gps.push_back({ { i + 1,j + 1 },knightposs(i + 1, j + 1)[k] });
                }
            }
            if (board[i][j] == color * 3) {
                for (size_t k = 0; k < (bishopposs(i + 1, j + 1).size()); k++) {
                    gps.push_back({ { i + 1,j + 1 },bishopposs(i + 1, j + 1)[k] });
                }
            }
            if (board[i][j] == color * 4) {
                for (size_t k = 0; k < (queenposs(i + 1, j + 1).size()); k++) {
                    gps.push_back({ { i + 1,j + 1 },queenposs(i + 1, j + 1)[k] });
                }
            }
            if (board[i][j] == color * 5) {
                for (size_t k = 0; k < (kingposs(i + 1, j + 1, color).size()); k++) {
                    gps.push_back({ { i + 1,j + 1 },kingposs(i + 1, j + 1,color)[k] });
                }
            }
        }
    }
    vector<vector<int>>board2;
    for (size_t i = 0; i < gps.size(); i++) {
        board2 = board;
        int a = gps[i][0][0];
        int b = gps[i][0][1];
        int x = gps[i][1][0];
        int y = gps[i][1][1];
        board2[x][y] = board2[a][b];
        board2[a][b] = 0;
        if( inadmissible_step(board2,color)){
            gps.erase(gps.begin() + i);
        }
    }
    return gps;
}

bool inadmissible_step(vector<vector<int>> board, int color) {

    set<vector<int>> gps;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == (color * 6)) {
                for (size_t k = 0; k < pawnattack(i + 1, j + 1, board, color).size(); k++) {
                    gps.insert({ pawnattack(i + 1, j + 1, board,color)[k] });
                }

            }
            if (board[i][j] == (color * 1)) {
                for (size_t k = 0; k < rookattack(i + 1, j + 1, board).size(); k++) {
                    gps.insert(rookattack(i + 1, j + 1, board)[k]);
                }
            }
            if (board[i][j] == (color * 2)) {
                for (size_t k = 0; k < (knightattack(i + 1, j + 1, board).size()); k++) {
                    gps.insert(knightattack(i + 1, j + 1, board)[k]);
                }
            }
            if (board[i][j] == (color * 3)) {
                for (size_t k = 0; k < (bishopattack(i + 1, j + 1, board).size()); k++) {
                    gps.insert(bishopattack(i + 1, j + 1, board)[k]);
                }
            }
            if (board[i][j] == (color * 4)) {
                for (size_t k = 0; k < (queenattack(i + 1, j + 1, board).size()); k++) {
                    gps.insert(queenattack(i + 1, j + 1, board)[k]);
                }
            }
            if (board[i][j] == (color * 5)) {
                for (size_t k = 0; k < (kingattack(i + 1, j + 1, board).size()); k++) {
                    gps.insert(kingattack(i + 1, j + 1, board)[k]);
                }
            }
        }
    }


    vector <int> a;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == color * 5) {
                a = { i,j };
            }
        }
    }

    if (find(gps.begin(), gps.end(), a) != gps.end()) {
        return false;
    }
    return true;

}
    vector<vector<int>> pawnattack(int x, int y,vector<vector<int>> board, int color) {
        vector <vector <int>> steps;
        if (color = 1) {
            if (x < 8 && y < 8 && board[x + 1][y + 1] >= 0) {
                steps.push_back({ x + 1,y + 1 });
            }
            if (x > 1 && y < 8 && board[x - 1][y + 1] >= 0) {
                steps.push_back({ x - 1,y + 1 });
            }
        }
        else {
            if (x < 8 && y >1 && board[x + 1][y - 1] <= 0) {
                steps.push_back({ x + 1,y - 1 });
            }
            if (x > 1 && y > 1 && board[x - 1][y - 1] <= 0) {
                steps.push_back({ x - 1,y - 1 });
            }
        }
        return steps;
    }
    vector<vector<int>> rookattack(int x, int y, vector<vector<int>> board) {
        vector <vector <int>> steps;
        while (x < 8) {
            if (board[x + 1][y] <= 0) {
                steps.push_back({ x + 1,y });
                break;
            }
            else {
                steps.push_back({ x + 1,y });
                x++;
            }
        }
        while (x > 1) {
            if (board[x - 1][y] <= 0) {
                steps.push_back({ x - 1,y });
                break;
            }
            else {
                steps.push_back({ x - 1,y });
                x--;
            }
        }
        while (y < 8) {
            if (board[x][y + 1] <= 0) {
                steps.push_back({ x,y + 1 });
                break;
            }
            else {
                steps.push_back({ x,y + 1 });
                y++;
            }
        }
        while (y > 1) {
            if (board[x][y - 1] <= 0) {
                steps.push_back({ x,y - 1 });
                break;
            }
            else {
                steps.push_back({ x,y - 1 });
                y--;
            }
        }
        return steps;
    }
    vector<vector<int>> knightattack(int x, int y, vector<vector<int>> board) {
        vector <vector <int>> steps;
        if (x > 2) {
            if (y < 8 && board[x - 2][y + 1] <= 0) {
                steps.push_back({ x - 2,y + 1 });
            }
            if (y > 1 && board[x - 2][y - 1] <= 0) {
                steps.push_back({ x - 2,y - 1 });
            }
        }
        if (y < 7) {
            if (x > 1 && board[x - 1][y + 2] <= 0) {
                steps.push_back({ x - 1,y + 2 });
            }
            if (x < 8 && board[x + 1][y + 2] <= 0) {
                steps.push_back({ x + 1,y + 2 });
            }
        }
        if (x < 7) {
            if (y < 8 && board[x + 2][y + 1] <= 0) {
                steps.push_back({ x + 2,y + 1 });
            }
            if (y > 1 && board[x + 2][y - 1] <= 0) {
                steps.push_back({ x + 2,y - 1 });
            }
        }
        if (y > 2) {
            if (x < 8 && board[x + 1][y - 2] <= 0) {
                steps.push_back({ x + 1,y - 2 });
            }
            if (x > 1 && board[x - 1][y - 2] <= 0) {
                steps.push_back({ x - 1,y - 2 });
            }
        }
        return steps;
    }
    vector<vector<int>>bishopattack(int x, int y, vector<vector<int>> board) {
        vector <vector <int>> steps;
        while (x < 8 && y < 8) {
            if (board[x + 1][y + 1] <= 0) {
                steps.push_back({ x + 1,y + 1 });
                break;
            }
            steps.push_back({ x + 1,y + 1 });
            x++;
            y++;
        }
        while (x < 8 && y>1) {
            if (board[x + 1][y - 1] <= 0) {
                steps.push_back({ x + 1,y - 1 });
                break;
            }
            steps.push_back({ x + 1,y - 1 });
            x++;
            y--;
        }
        while (x > 1 && y > 1) {
            if (board[x - 1][y - 1] <= 0) {
                steps.push_back({ x - 1,y - 1 });
                break;
            }
            steps.push_back({ x - 1,y - 1 });
            x--;
            y--;
        }
        while (x < 1 && y < 8) {
            if (board[x - 1][y + 1] <= 0) {
                steps.push_back({ x - 1,y + 1 });
                break;
            }
            steps.push_back({ x - 1,y + 1 });
            x--;
            y++;
        }
        return steps;

    }
    vector<vector<int>> queenattack(int x, int y, vector<vector<int>> board) {
        vector <vector <int>> steps;
        while (x < 8) {
            if (board[x + 1][y] <= 0) {
                steps.push_back({ x + 1,y });
                break;
            }
            else {
                steps.push_back({ x + 1,y });
                x++;
            }
        }
        while (x > 1) {
            if (board[x - 1][y] <= 0) {
                steps.push_back({ x - 1,y });
                break;
            }
            else {
                steps.push_back({ x - 1,y });
                x--;
            }
        }
        while (y < 8) {
            if (board[x][y + 1] <= 0) {
                steps.push_back({ x,y + 1 });
                break;
            }
            else {
                steps.push_back({ x,y + 1 });
                y++;
            }
        }
        while (y > 1) {
            if (board[x][y - 1] <= 0) {
                steps.push_back({ x,y - 1 });
                break;
            }
            else {
                steps.push_back({ x,y - 1 });
                y--;
            }
        }
        while (x < 8 && y < 8) {
            if (board[x + 1][y + 1] <= 0) {
                steps.push_back({ x + 1,y + 1 });
                break;
            }
            steps.push_back({ x + 1,y + 1 });
            x++;
            y++;
        }
        while (x < 8 && y>1) {
            if (board[x + 1][y - 1] <= 0) {
                steps.push_back({ x + 1,y - 1 });
                break;
            }
            steps.push_back({ x + 1,y - 1 });
            x++;
            y--;
        }
        while (x > 1 && y > 1) {
            if (board[x - 1][y - 1] <= 0) {
                steps.push_back({ x - 1,y - 1 });
                break;
            }
            steps.push_back({ x - 1,y - 1 });
            x--;
            y--;
        }
        while (x < 1 && y < 8) {
            if (board[x - 1][y + 1] <= 0) {
                steps.push_back({ x - 1,y + 1 });
                break;
            }
            steps.push_back({ x - 1,y + 1 });
            x--;
            y++;
        }
        return steps;

    }
    vector<vector<int>> kingattack(int x, int y, vector<vector<int>> board) {
        vector <vector <int>> steps;
        if (y < 8) {
            steps.push_back({ x, y + 1 });
            if (x < 8) {
                steps.push_back({ x + 1, y + 1 });
            }
        }
        if (x < 8) {
            steps.push_back({ x + 1, y });
            if (y > 1) {
                steps.push_back({ x + 1, y - 1 });
            }
        }
        if (y > 1) {
            steps.push_back({ x, y - 1 });
            if (x > 1) {
                steps.push_back({ x - 1, y - 1 });
            }
        }
        if (x > 1) {
            steps.push_back({ x - 1, y });
            if (y < 8) {
                steps.push_back({ x - 1, y + 1 });
            }
        }

    }
vector<vector<int>> Board::pawnposs(int x, int y, int color) {
    vector <vector <int>> steps;
    if (color = 1) {
        if (x < 8 && y < 8 && board[x + 1][y + 1] < 0) {
            steps.push_back({ x + 1,y + 1 });
        }
        if (x > 1 && y < 8 && board[x - 1][y + 1] < 0) {
            steps.push_back({ x - 1,y + 1 });
        }
        if (y == 2 && board[x][y + 1] == 0 && board[x][y + 2] == 0) {
            steps.push_back({ x,y + 2 });
        }
        if (y < 8 && board[x][y + 1] == 0) {
            steps.push_back({ x,y + 1 });
        }
    }

    else {
        if (x < 8 && y >1 && board[x + 1][y - 1] > 0) {
            steps.push_back({ x + 1,y - 1 });
        }
        if (x > 1 && y > 1 && board[x - 1][y - 1] > 0) {
            steps.push_back({ x - 1,y - 1 });
        }
        if (y == 7 && board[x][y - 1] == 0 && board[x][y - 2] == 0) {
            steps.push_back({ x,y - 2 });
        }
        if (y > 1 && board[x][y - 1] == 0) {
            steps.push_back({ x,y - 1 });
        }
    }
    return steps;
}
vector<vector<int>> Board::rookposs(int x, int y) {
    vector <vector <int>> steps;
    while (x < board.size() - 1) {
        if (board[x + 1][y] > 0) {
            break;
        }
        if (board[x + 1][y] < 0) {
            steps.push_back({ x + 1,y });
            break;
        }
        else {
            steps.push_back({ x + 1,y });
            x++;
        }
    }
    while (x > 0) {
        if (board[x - 1][y] > 0) {
            break;
        }
        if (board[x - 1][y] < 0) {
            steps.push_back({ x - 1,y });
            break;
        }
        else {
            steps.push_back({ x - 1,y });
            x--;
        }
    }
    while (y < board[0].size() - 1) {
        if (board[x][y + 1] > 0) {
            break;
        }
        if (board[x][y + 1] < 0) {
            steps.push_back({ x,y + 1 });
            break;
        }
        else {
            steps.push_back({ x,y + 1 });
            y++;
        }
    }
    while (y > 0) {
        if (board[x][y - 1] > 0) {
            break;
        }
        if (board[x][y - 1] < 0) {
            steps.push_back({ x,y - 1 });
            break;
        }
        else {
            steps.push_back({ x,y - 1 });
            y--;
        }
    }
    return steps;
}
vector<vector<int>> Board::knightposs(int x, int y) {
    vector <vector <int>> steps;
    if (x > 2) {
        if (y < 8 && board[x - 2][y + 1] <= 0) {
            steps.push_back({ x - 2,y + 1 });
        }
        if (y > 1 && board[x - 2][y - 1] <= 0) {
            steps.push_back({ x - 2,y - 1 });
        }
    }
    if (y < 7) {
        if (x > 1 && board[x - 1][y + 2] <= 0) {
            steps.push_back({ x - 1,y + 2 });
        }
        if (x < 8 && board[x + 1][y + 2] <= 0) {
            steps.push_back({ x + 1,y + 2 });
        }
    }
    if (x < 7) {
        if (y < 8 && board[x + 2][y + 1] <= 0) {
            steps.push_back({ x + 2,y + 1 });
        }
        if (y > 1 && board[x + 2][y - 1] <= 0) {
            steps.push_back({ x + 2,y - 1 });
        }
    }
    if (y > 2) {
        if (x < 8 && board[x + 1][y - 2] <= 0) {
            steps.push_back({ x + 1,y - 2 });
        }
        if (x > 1 && board[x - 1][y - 2] <= 0) {
            steps.push_back({ x - 1,y - 2 });
        }
    }
    return steps;
}
vector<vector<int>> Board::bishopposs(int x, int y) {
    vector <vector <int>> steps;
    while (x < 7 && y < 7) {
        if (board[x + 1][y + 1] > 0) {
            break;
        }
        steps.push_back({ x + 1,y + 1 });
        x++;
        y++;
    }
    while (x < 7 && y>2) {
        if (board[x + 1][y - 1]) {
            break;
        }
        steps.push_back({ x + 1,y - 1 });
        x++;
        y--;
    }
    while (x > 2 && y > 2) {
        if (board[x - 1][y - 1]) {
            break;
        }
        steps.push_back({ x - 1,y - 1 });
        x--;
        y--;
    }
    while (x < 2 && y < 7) {
        if (board[x - 1][y + 1]) {
            break;
        }
        steps.push_back({ x - 1,y + 1 });
        x--;
        y++;
    }
    return steps;

}
vector<vector<int>> Board::queenposs(int x, int y) {
    vector <vector <int>> steps;
    while (x < 7) {
        if (board[x + 1][y] > 0) {
            break;
        }
        else {
            steps.push_back({ x + 1,y });
            x++;
        }
    }
    while (x > 2) {
        if (board[x - 1][y] > 0) {
            break;
        }
        else {
            steps.push_back({ x - 1,y });
            x--;
        }
    }
    while (y < 7) {
        if (board[x][y + 1] > 0) {
            break;
        }
        else {
            steps.push_back({ x,y + 1 });
            y++;
        }
    }
    while (y > 2) {
        if (board[x][y - 1] > 0) {
            break;

        }
        else {
            steps.push_back({ x,y - 1 });
            y--;
        }
    }
    while (x < 7 && y < 7) {
        if (board[x + 1][y + 1] > 0) {
            break;
        }
        steps.push_back({ x + 1,y + 1 });
        x++;
        y++;
    }
    while (x < 7 && y>2) {
        if (board[x + 1][y - 1]) {
            break;
        }
        steps.push_back({ x + 1,y - 1 });
        x++;
        y--;
    }
    while (x > 2 && y > 2) {
        if (board[x - 1][y - 1]) {
            break;
        }
        steps.push_back({ x - 1,y - 1 });
        x--;
        y--;
    }
    while (x < 2 && y < 7) {
        if (board[x - 1][y + 1]) {
            break;
        }
        steps.push_back({ x - 1,y + 1 });
        x--;
        y++;
    }
    return steps;

}
vector<vector<int>> Board::kingposs(int x, int y, int color) {
    vector <vector <int>> steps;
    if (y < 7) {
        steps.push_back({ x, y + 1 });
        if (x < 7) {
            steps.push_back({ x + 1, y + 1 });
        }
    }
    if (x < 7) {
        steps.push_back({ x + 1, y });
        if (y > 1) {
            steps.push_back({ x + 1, y - 1 });
        }
    }
    if (y > 2) {
        steps.push_back({ x, y - 1 });
        if (x > 2) {
            steps.push_back({ x - 1, y - 1 });
        }
    }
    if (x > 2) {
        steps.push_back({ x - 1, y });
        if (y < 7) {
            steps.push_back({ x - 1, y + 1 });
        }
    }
    if (color == 1 && board[4][0] == 5 && check(under_attack( -1), 1) == false) {
        if (board[5][0] == 0 && board[6][0] == 0 && board[7][0] == 1) {
            steps.push_back({ 7,1,8,1,6,1 });
        }
        if (board[3][0] == 0 && board[2][0] == 0 && board[1][0] == 0 && board[0][0] == 1) {
            steps.push_back({ 3,1,1,1,4,1 });

        }
    }
    if (color == -1 && board[4][7] == -5 && check(under_attack( 1), -1) == false) {
        if (board[5][7] == 0 && board[6][7] == 0 && board[7][7] == -1) {
            steps.push_back({ 7, 8,8,8,6,8 });
        }
        if (board[3][7] == 0 && board[2][7] == 0 && board[1][7] == 0 && board[0][7] == -1) {
            steps.push_back({ 3, 8 ,1,8,4,8 });

        }
    }


    for (size_t i = 0; i < steps.size(); i++) {

        if (find(under_attack( -1 * color).begin(), under_attack( -1 * color).end(), steps[i]) != under_attack( -1 * color).end()) {
            steps.erase(steps.begin() + i);
        }
    }
    return steps;
}

bool Board::check(set<vector<int>> vec,  int color) {

    vector <int> a;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == color * 5) {
                a = { i,j };
            }
        }
    }
    if (find(vec.begin(), vec.end(), a) != vec.end()) {
        return false;
    }
    return true;
}


void Board::move(string posit, string step) {
    bool t = false;
    int a, b, c, d, x, y, z, j;

    if (posit.size() > 2 && step.size() > 2) {
        a = int(posit[0]) - 96;
        b = int(posit[1] - 1);
        x = int(step[0]) - 96;
        y = int(step[1] - 1);
        c = int(posit[2]) - 96;
        d = int(posit[3] - 1);
        z = int(step[2]) - 96;
        j = int(step[3] - 1);
        for (int i = 0; i < general_poss_st( -1).size(); i++) {
            if (general_poss_st( -1)[i][1].size() == 4 && general_poss_st( -1)[i][0][0] == a && general_poss_st( -1)[i][0][1] == b
                && general_poss_st( -1)[i][1][0] == x && general_poss_st( -1)[i][1][1] == y
                && general_poss_st( -1)[i][1][2] == c && general_poss_st( -1)[i][1][3] == d
                && general_poss_st( -1)[i][1][4] == z && general_poss_st( -1)[i][1][5] == j) {
                t = true;
                break;
            }
        }
    }
    else {
        int a = int(posit[0]) - 96;
        int b = int(posit[1]) - 48;
        int x = int(step[0]) - 96;
        int y = int(step[1]) - 48;

        for (int i = 0; i < general_poss_st( -1).size(); i++) {
            if (general_poss_st( -1)[i][1].size() == 2 && general_poss_st( -1)[i][0][0] == a && general_poss_st( -1)[i][0][1] == b
                && general_poss_st( -1)[i][1][0] == x && general_poss_st( -1)[i][1][1] == y) {
                t = true;
                break;
            }
        }
    }

    if (t == false) {
        cout << "An inadmissible step";
        cin >> posit;
        cin >> step;
        move(posit, step);
    }
    if (posit.size() > 2 && step.size() > 2) {
        board[x - 1][y - 1] = board[a - 1][b - 1];
        board[a - 1][b - 1] = 0;
        board[z - 1][j - 1] = board[c - 1][d - 1];
        board[c - 1][d - 1] = 0;
    }
    else {
        board[x - 1][y - 1] = board[a - 1][b - 1];
        board[a - 1][b - 1] = 0;
    }

    int m = rand() % (general_poss_st( 1).size() - 1);
    if (general_poss_st( 1)[m][1].size() == 2) {
        a = general_poss_st( 1)[m][0][0];
        b = general_poss_st( 1)[m][0][1];
        x = general_poss_st( 1)[m][1][0];
        y = general_poss_st( 1)[m][1][1];
        board[x][y] = board[a][b];
        board[a][b] = 0;
    }
    else {
        a = general_poss_st( 1)[m][0][0];
        b = general_poss_st( 1)[m][0][1];
        x = general_poss_st( 1)[m][1][0];
        y = general_poss_st( 1)[m][1][1];

        c = general_poss_st( 1)[m][1][2];
        d = general_poss_st( 1)[m][1][3];
        z = general_poss_st(1)[m][1][4];
        j = general_poss_st( 1)[m][1][5];

        board[x - 1][y - 1] = board[a - 1][b - 1];
        board[a - 1][b - 1] = 0;
        board[z - 1][j - 1] = board[c][d];
        board[c - 1][d - 1] = 0;
    }
    print(board);
}
