
#pragma once

#include <vector>
#include "PPU.hpp"

enum IF_TYPE{
	GUI, 
	TEXT
};

class program{
	private:
		std::vector<PPU> game_interfaces;
		
	public:
		void new_game(IF_TYPE type);
		//add_game
};
