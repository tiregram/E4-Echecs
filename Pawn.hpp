#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
	Pawn(bool isBlack, Plat* pl);
	virtual bool check(const ChessAction &a) const;
	virtual ~Pawn();
};
