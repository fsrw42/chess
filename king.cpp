#include "king.hpp"

#define ADD_MOVE(y,x) (\
(this->can_move(y, x, board))&&\
(moves[y][x] = true)\
)

King::King(bool isWhite)
{
	type = 'k';
	texture.loadFromFile("pieces.png", sf::IntRect(0, 0+((int)!isWhite)*320, 320, 320));
	texture.setSmooth(true);
	mainObj.setTexture(texture);
	mainObj.setScale(sf::Vector2f(0.19375,0.19375));
	this->isWhite = isWhite;
}

bool King::can_move(int y, int x, Piece* board[8][8], bool *stop = nullptr)
{ 
	if(x < 0 || x >= 8)
		return false;

	if(y < 0 || y >= 8)
		return false;

	if(board[y][x] != nullptr)
	{
		if((board[y][x])->is_white() != this->is_white())
		{
			if(stop != nullptr)
				*stop = true;
			return true;
		}
		else if(stop != nullptr)
		{
			*stop = true;
		}
	}

	if(board[y][x] == nullptr)
		return true;

	return false;
}

void King::get_legal_moves(bool moves[8][8], Piece* board[8][8], unsigned short x, unsigned short y)
{
	ADD_MOVE(y+1, x+1);
	ADD_MOVE(y+1, x-1);
	ADD_MOVE(y-1, x+1);
	ADD_MOVE(y-1, x-1);
	ADD_MOVE(y+1, x);
	ADD_MOVE(y-1, x);
	ADD_MOVE(y, x+1);
	ADD_MOVE(y, x-1);
}
