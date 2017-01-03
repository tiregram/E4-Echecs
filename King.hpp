#pragma once 
#include "Piece.hpp"

class King : public Piece {
public:
	King(bool isBlack, Plat* pl);
	virtual bool check(const ChessAction &a) const; 
	virtual ~King();
};
