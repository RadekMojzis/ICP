
#pragma once

#include <vector>
#include "PPU.hpp"

class program{
	private:
        interface &game_interfa;
		
	public:
        void new_game(interface &IF){game_interfa = IF};
		//add_game
};
