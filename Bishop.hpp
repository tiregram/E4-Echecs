#pragma once 

#include "Piece.hpp"
class Bishop : public Piece {
public:
	Bishop(bool isBlack, Plat* pl);
	virtual bool check(const ChessAction &a) const;
	virtual ~Bishop();
};
