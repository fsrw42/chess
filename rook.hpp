#include "piece.hpp"

class Rook : protected Piece
{
public:
	Rook(bool);
	virtual bool can_move(int, int, Piece*[8][8], bool*);
	virtual void get_legal_moves(bool[8][8], Piece*[8][8], unsigned short, unsigned short);
};
