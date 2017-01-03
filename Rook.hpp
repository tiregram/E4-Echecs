#pragma once 
#include "Piece.hpp"
class Rook : public Piece {
public:
	Rook(bool isBlack, Plat* pl);
	virtual bool check(const ChessAction &a) const;
	virtual ~Rook();
};
