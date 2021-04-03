#include "GameOfLife.h"

#include <stdio.h>
#include <iostream>

GameOfLife::GameOfLife() {
    srand (time(NULL));
    for(auto &l : matrix) {
        for(bool &b : l) {
            b = (rand() %24) < 1;
        }
    }
}

void GameOfLife::loop() {
    system("clear");
    print();
    update();

    std::cin.ignore();
}

const void GameOfLife::print() {
    for(const auto &l : matrix) {
        for(const bool &b : l) {
            std::cout << (b ? "X" : " ");
        }
        std::cout <<"\n";
    }
}

const bool GameOfLife::calculateLife(int j, int k) {
    // count neighbour
    auto count = 0;
    for(auto row = (j-1); row < (j+1); row++) {
        for(auto col = (k-1); col < (k+1); col++) {
            if(matrix[row][col]) {
                count++;
            }
        }
    }
    if(matrix[j][k]) count--;
    
    // update
    if(count == 3) {
        return true;
    } else if(matrix[j][k] && count == 2) {
        return true;
    } else {
        return false;
    }
}

const bool GameOfLife::at(int row, int col) {
    return matrix[row][col];
}

void GameOfLife::update() {
    Matrix result;
    for(auto j = 1; j < cWidth_game-1; j++) {
        for(auto k = 1; k < cHeight_game-1; k++) {
            result[j][k] = calculateLife(j, k);
        }
    }
    matrix = result;
}
