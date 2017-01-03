#pragma once 
#include "Piece.hpp"
class Knight : public Piece {
public:
	Knight(bool isBlack, Plat* pl);
	virtual bool check(const ChessAction &a) const;
	virtual ~Knight();
};
