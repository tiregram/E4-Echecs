#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
	bool hasntMoved(const ChessAction &a)const;
	Pawn(bool isBlack, Plat* pl);
	virtual bool check(const ChessAction &a) const;
	virtual ~Pawn();
};
