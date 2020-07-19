#include "utils.h"
#include <iostream>
void print(std::vector <std::vector<int>> v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            if (v[i][j] >= 0) {
                std::cout << " ";
            }
        }
        std::cout <<std::endl;
    }

}