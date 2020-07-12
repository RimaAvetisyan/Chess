#include "utils.h"
void print(vector <vector<int>> v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (v[i][j] >= 0) {
                cout << " ";
            }
        }
        cout << endl;
    }

}