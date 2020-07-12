#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "Board.h"
#include "utils.h"
using namespace std;


int main()
{
    Board ob;
    vector<vector<int>> vec = ob.board;
    bool checkwhite = false;
    bool checkblack;
    string posit;
    string step;
    bool game_over = false;
    bool win = false;
    while (game_over == false && win==false) {
        print(ob.board);
        cin >> posit;
        cin >> step;
        ob.move( posit, step);
        checkwhite = ob.check(ob.under_attack(-1),1);
        checkblack= ob.check(ob.under_attack( 1),-1);
        if (checkwhite && ob.general_poss_st( 1).empty()) {
            game_over = true;
            cout << "You win";
            break;
        }
        else if(checkblack && ob.general_poss_st( -1).empty()) {
            game_over = true;
            cout << "You lost";
            break;
        }
    }
    return 0;
}