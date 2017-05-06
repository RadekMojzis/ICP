
#pragma once

#include <vector>
#include "interface.hpp"

enum IF_TYPE{
    GUI,
    TEXT
};


class program{
	private:
        GPU gpu;
        PPU ppu;
        IF_TYPE interface;
	public:
        void new_game();
        program(IF_TYPE IF);
        //add_game
};
