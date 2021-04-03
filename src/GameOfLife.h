#pragma once

#include <array>

constexpr auto cWidth_game = 300;
constexpr auto cHeight_game = 300;

using Line = std::array<bool, cWidth_game>;
using Matrix = std::array<Line, cHeight_game>;

class GameOfLife {
    public:
        GameOfLife();
        void loop();
        const void print();
        void update();
        const bool at(int row, int col);

    private:
        const bool calculateLife(int j, int k);
        
        Matrix matrix;
};
