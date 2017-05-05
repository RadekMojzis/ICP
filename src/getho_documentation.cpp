class program{
	private:
		std::vector<game> games;
	public:
		create_game();
		//add_game
}

// Or PePeU
class PPU{
	private:
		//Cosi s qt... uz to stahuju...
		//prozatim stdout
		std::fstream output;
	public:
		draw_card(const Card &card); // card and position
		draw_deck(int DeckID); // mozna neco jineho
}

// drawing stejnak musi delat nejaky stack of cards..
class Card{
	private:
		int id;
		bool face_up;
	public:
		flip();
		get_id();
		is_up();
}

class Action{
	private:
		Stack_of_cards &from;
		Stack_of_cards &to;
		Card &what;
	public:
		execute(Game &game);
		reverse();
}

class Deck{ 
	// a master class of all card stacks
	private:
	  std::vector<Card> cards;
	public:
	 draw();
}

class Stock:Deck{
	// The thing you draw cards from
	private:
	public:
}

class Flip:Deck{
	// you put cards from deck here
	private:
	public:
}

class Pile:Deck{
	// you play on these
	private:
	public:
}

class Foundation:Deck{
	private:
	public:
	// here you want to put all cards
}
