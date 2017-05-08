
#pragma once

#include <vector>
#include "interface.hpp"
#include "gcard.h"
enum IF_TYPE{
    GUI,
    TEXT
};


class program{
	private:
        GPU *gpu;
        PPU *ppu;
        IF_TYPE cosi;
	public:
        void new_game();
        program(IF_TYPE IF);
        //add_game
};
