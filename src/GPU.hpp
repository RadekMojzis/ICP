

#pragma once
#include "interface.hpp"

class GPU: public interface{
	// you put cards from deck here
	private:
		CardIndex drawing_card;
	public:
        GPU();
};
