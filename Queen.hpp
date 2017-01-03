#pragma once 
#include "Piece.hpp"
class Queen : public Piece {
public:
	Queen(bool isBlack, Plat* pl);
	virtual bool check(const ChessAction &a) const;
	virtual ~Queen();
};
