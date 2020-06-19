#include <iostream>
#include <vector>
#include<set>
#include<cmath>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Chess {
public:
    vector <vector<int>> board = { {-1,-2,-3,-4,-5,-3,-2,-1},
                                   {-6,-6,-6,-6,-6,-6,-6,-6},
                                   { 0, 0, 0, 0, 0, 0, 0, 0},
                                   { 0, 0, 0, 0, 0, 0, 0, 0},
                                   { 0, 0, 0, 0, 0, 0, 0, 0},
                                   { 0, 0, 0, 0, 0, 0, 0, 0},
                                   { 6, 6, 6, 6, 6, 6, 6, 6},
                                   { 1, 2, 3, 4, 5, 3, 2, 1} };
    
    void move(string posit, string step);
    set<vector<int>> under_attack(vector<vector<int>>board, int color);
    vector<vector<vector<int>>> general_poss_st(vector<vector<int>>board, int color);
    vector<vector<int>> pawnposs(int x, int y,int color);
    vector<vector<int>> rookposs(int x, int y);
    vector<vector<int>> knightposs(int x, int y);
    vector<vector<int>> bishopposs(int x, int y);
    vector<vector<int>> queenposs(int x, int y);
    vector<vector<int>> kingposs(int x, int y,int color);
    bool  check(set<vector<int>> vec, vector<vector<int>> board, int color);

    vector<vector<int>> pawnattack(int x, int y, int color);
    vector<vector<int>> rookattack(int x, int y);
    vector<vector<int>> knightattack(int x, int y);
    vector<vector<int>> bishopattack(int x, int y);
    vector<vector<int>> queenattack(int x, int y);
    vector<vector<int>> kingattack(int x, int y);
};



set<vector<int>> Chess:: under_attack(vector<vector<int>>board1, int color) {
    set<vector<int>> gps;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board1[i][j] == color*6) {
                for (size_t k = 0; k < pawnattack(i + 1, j + 1,color).size(); k++) {
                    gps.insert({ pawnattack(i + 1, j + 1,color)[k] });
                }

            }
            if (board1[i][j] == color * 1) {
                for (size_t k = 0; k < rookattack(i + 1, j + 1).size(); k++) {
                    gps.insert( rookattack(i + 1, j + 1)[k] );
                }
            }
            if (board1[i][j] == color * 2) {
                for (size_t k = 0; k < (knightattack(i + 1, j + 1).size()); k++) {
                    gps.insert( knightattack(i + 1, j + 1)[k] );
                }
            }
            if (board1[i][j] == color * 3) {
                for (size_t k = 0; k < (bishopattack(i + 1, j + 1).size()); k++) {
                    gps.insert( bishopattack(i + 1, j + 1)[k] );
                }
            }
            if (board1[i][j] == color * 4) {
                for (size_t k = 0; k < (queenattack(i + 1, j + 1).size()); k++) {
                    gps.insert( queenattack(i + 1, j + 1)[k] );
                }
            }
            if (board1[i][j] == color * 5) {
                for (size_t k = 0; k < (kingattack(i + 1, j + 1).size()); k++) {
                    gps.insert( kingattack(i + 1, j + 1)[k] );
                }
            }
        }
    }
    return gps;
}

vector<vector<int>> Chess:: pawnattack(int x, int y, int color) {
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
vector<vector<int>> Chess:: rookattack(int x, int y) {
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
vector<vector<int>> Chess:: knightattack(int x, int y) {
    vector <vector <int>> steps;
    if (x > 2) {
        if (y < 8 && board[x-2][y+1]<=0) {
            steps.push_back({ x - 2,y + 1 });
        }
        if (y > 1 && board[x-2][y-1]<=0) {
            steps.push_back({ x - 2,y - 1 });
        }
    }
    if (y < 7) {
        if (x > 1 && board[x-1][y+2]<=0) {
            steps.push_back({ x - 1,y + 2 });
        }
        if (x < 8 && board[x+1][y+2]<=0) {
            steps.push_back({ x + 1,y + 2 });
        }
    }
    if (x < 7) {
        if (y < 8 && board[x+2][y+1]<=0) {
            steps.push_back({ x + 2,y + 1 });
        }
       if (y > 1 && board[x+2][y-1]<=0) {
            steps.push_back({ x + 2,y - 1 });
        }
    }
    if (y > 2) {
        if (x < 8 && board[x+1][y-2]<=0 ) {
            steps.push_back({ x + 1,y - 2 });
        }
        if (x > 1 && board[x-1][y-2]<=0) {
            steps.push_back({ x - 1,y - 2 });
        }
    }
    return steps;
}
vector<vector<int>> Chess:: bishopattack(int x, int y) {
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
        if (board[x + 1][y - 1]<=0) {
            steps.push_back({ x + 1,y - 1 });
            break;
        }
        steps.push_back({ x + 1,y - 1 });
        x++;
        y--;
    }
    while (x > 1 && y > 1) {
        if (board[x - 1][y - 1]<=0) {
            steps.push_back({ x - 1,y - 1 });
            break;
        }
        steps.push_back({ x - 1,y - 1 });
        x--;
        y--;
    }
    while (x < 1 && y < 8) {
        if (board[x - 1][y + 1]<=0) {
            steps.push_back({ x - 1,y + 1 });
            break;
        }
        steps.push_back({ x - 1,y + 1 });
        x--;
        y++;
    }
    return steps;

}
vector<vector<int>> Chess:: queenattack(int x, int y) {
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
vector<vector<int>> Chess:: kingattack(int x, int y) {
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
vector<vector<vector<int>>> Chess:: general_poss_st(vector<vector<int>> board, int color) {
    vector<vector<vector<int>>> gps;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == color * 6) {
                for (size_t k = 0; k < pawnposs(i + 1, j + 1,color).size(); k++) {
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
                for (size_t k = 0; k < (kingposs(i + 1, j + 1,color).size()); k++) {
                    gps.push_back({ { i + 1,j + 1 },kingposs(i + 1, j + 1,color)[k] });
                }
            }
        }
    }
    vector<vector<int>>board2;
    board2 = board;
    for (size_t i = 0; i < gps.size(); i++) {
        board2 = board;
       int a = gps[i][0][0];
       int b = gps[i][0][1];
       int x = gps[i][1][0];
       int y = gps[i][1][1];
       board2[x][y] = board2[a][b];
       board2[a][b] = 0;
       if (check(under_attack(board2,-1),board,1)) {
           gps.erase(gps.begin() + i);
        }
    }
    return gps;
}
vector<vector<int>> Chess::pawnposs(int x, int y, int color) {
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
        if (x > 1 && y >1 && board[x - 1][y - 1] > 0) {
            steps.push_back({ x - 1,y - 1 });
        }
        if (y == 7 && board[x][y - 1] == 0 && board[x][y - 2] == 0) {
            steps.push_back({ x,y - 2 });
        }
        if (y >1 && board[x][y - 1] == 0) {
            steps.push_back({ x,y - 1 });
        }
    }
    return steps;
}
vector<vector<int>> Chess::rookposs(int x, int y) {
    vector <vector <int>> steps;
    while (x < board.size()-1) {
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
    while (y < board[0].size()-1) {
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
vector<vector<int>> Chess:: knightposs(int x, int y) {
    vector <vector <int>> steps;
    if (x > 2) {
        if (y < 8 && board[x-2][y+1]<=0) {
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
        if (y > 1 && board[x +2][y -1] <= 0 ){
            steps.push_back({ x + 2,y - 1 });
        }
    }
    if (y > 2) {
        if (x < 8 && board[x +1 ][y -2] <= 0) {
            steps.push_back({ x + 1,y - 2 });
        }
        if (x > 1 && board[x - 1][y -2] <= 0) {
            steps.push_back({ x - 1,y - 2 });
        }
    }
    return steps;
}
vector<vector<int>> Chess:: bishopposs(int x, int y) {
    vector <vector <int>> steps;
    while (x < 8 && y < 8) {
        if (board[x + 1][y + 1] > 0) {
            break;
        }
        steps.push_back({ x + 1,y + 1 });
        x++;
        y++;
    }
    while (x < 8 && y>1) {
        if (board[x + 1][y - 1]) {
            break;
        }
        steps.push_back({ x + 1,y - 1 });
        x++;
        y--;
    }
    while (x > 1 && y > 1) {
        if (board[x - 1][y - 1]) {
            break;
        }
        steps.push_back({ x - 1,y - 1 });
        x--;
        y--;
    }
    while (x < 1 && y < 8) {
        if (board[x - 1][y + 1]) {
            break;
        }
        steps.push_back({ x - 1,y + 1 });
        x--;
        y++;
    }
    return steps;

}
vector<vector<int>> Chess:: queenposs(int x, int y) {
    vector <vector <int>> steps;
    while (x < 8) {
        if (board[x + 1][y] > 0) {
            break;
        }
        else {
            steps.push_back({ x + 1,y });
            x++;
        }
    }
    while (x > 1) {
        if (board[x - 1][y] > 0) {
            break;
        }
        else {
            steps.push_back({ x - 1,y });
            x--;
        }
    }
    while (y < 8) {
        if (board[x][y + 1] > 0) {
            break;
        }
        else {
            steps.push_back({ x,y + 1 });
            y++;
        }
    }
    while (y > 1) {
        if (board[x][y - 1] > 0) {
            break;

        }
        else {
            steps.push_back({ x,y - 1 });
            y--;
        }
    }
    while (x < 8 && y < 8) {
        if (board[x + 1][y + 1] > 0) {
            break;
        }
        steps.push_back({ x + 1,y + 1 });
        x++;
        y++;
    }
    while (x < 8 && y>1) {
        if (board[x + 1][y - 1]) {
            break;
        }
        steps.push_back({ x + 1,y - 1 });
        x++;
        y--;
    }
    while (x > 1 && y > 1) {
        if (board[x - 1][y - 1]) {
            break;
        }
        steps.push_back({ x - 1,y - 1 });
        x--;
        y--;
    }
    while (x < 1 && y < 8) {
        if (board[x - 1][y + 1]) {
            break;
        }
        steps.push_back({ x - 1,y + 1 });
        x--;
        y++;
    }
    return steps;

}
vector<vector<int>> Chess:: kingposs(int x, int y, int color) {
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
    if ( color==1 && board[4][0] == 5 && check(under_attack(board,-1),board,1) == false) {
        if (board[5][0] == 0 && board[6][0] == 0 && board[7][0] == 1) {
            steps.push_back({ 7, 1,6,1});
        }
        if (board[3][0] == 0 && board[2][0] == 0 && board[1][0] == 0 && board[0][0] == 1) {
            steps.push_back({ 3, 1 ,4,1});
            
        }
    }
    if (color == -1 && board[4][7] == -5 && check(under_attack(board, 1), board, -1) == false) {
        if (board[5][7] == 0 && board[6][7] == 0 && board[7][7] == -1) {
            steps.push_back({ 7, 8,6,8 });
        }
        if (board[3][7] == 0 && board[2][7] == 0 && board[1][7] == 0 && board[0][7] == -1) {
            steps.push_back({ 3, 8 ,4,8 });

        }
    }
  
 
for (size_t i = 0; i < steps.size(); i++) {
   
    if (find(under_attack(board,-1).begin(), under_attack(board,-1).end(), steps[i]) != under_attack(board,-1).end()) {
        steps.erase(steps.begin() + i);
    }
}
return steps;
}

bool Chess:: check(set<vector<int>> vec, vector<vector<int>> board, int color) {
   
    vector <int> a;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] ==color* 5) {
                a = { i,j };
            }
        }
    }
        if (find(vec.begin(), vec.end(), a) != vec.end()) {
            return false;
        }
        return true;
}

int print(vector <vector<int>> v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (v[i][j] >= 0) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

void Chess::move(string posit, string step) {
    int a = int(posit[0]) - 97;
    int b = int(posit[1])-1;
    int x = int(step[0]) - 97;
    int y = int(step[1])-1;
    bool t = false;
    for (int i = 0; i < general_poss_st(board, -1).size(); i++) {
        for (int j = 0; j < general_poss_st(board, -1)[i].size(); j++) {
            if (general_poss_st(board, -1)[i][j].size()==2 && general_poss_st(board, -1)[i][j][0] == x && general_poss_st(board, -1)[i][j][1] == y) {
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
        board[x][y] = board[a][b];
        board[a][b] = 0;

        int m = rand() % (general_poss_st(board,1).size()-1);
       
         a = general_poss_st(board,1)[m][0][0];
         b = general_poss_st(board,1)[m][0][1];
         x = general_poss_st(board,1)[m][1][0];
         y = general_poss_st(board,1)[m][1][1];
        board[x][y] = board[a][b];
        board[a][b] = 0;
        print(board);
    }

int main()
{
    Chess ob;
    vector<vector<int>> vec = ob.board;
    bool checkwhite = false;
    bool checkblack;
    string posit;
    string step;
    bool game_over = false;
    bool win = false;
    while (game_over == false) {
        print(ob.board);
        cin >> posit;
        cin >> step;
        ob.move( posit, step);
        checkwhite = ob.check(ob.under_attack(ob.board,-1),ob.board,1);
        checkblack= ob.check(ob.under_attack(ob.board, 1), ob.board, -1);
        if (checkwhite && ob.general_poss_st(ob.board, 1).empty()) {
            game_over = true;
            cout << "You win";
            break;
        }
        else if(checkblack && ob.general_poss_st(ob.board, -1).empty()) {
            game_over = true;
            cout << "You lost";
            break;
        }
    }
    return 0;
}