#include "Pawn.hpp"
#include <utility>
#include <math.h>

Pawn::Pawn(bool isBlack, Plat* pl) : Piece("Pawn", 'r', isBlack, pl) {}

bool Pawn::check(const ChessAction &a) const {
  return true ;
  /*
	std::pair<int, int> from = convertS2P(a.from);
	std::pair<int, int> to = convertS2P(a.to);

	Plat::Pie_ptr MovingPiece = plate->getPieceAt(a.from);
	Plat::Pie_ptr ToEatPiece;

	int dx = from.first - to.first;
	int dy = from.second - to.second;
	
	if (plate->getPieceAt(a.to)) 
	{
		ToEatPiece = plate->getPieceAt(a.to);

		if (MovingPiece->isBlack)
		{
			if (!ToEatPiece->isBlack && abs(dx) == 1 && dy == 1)
			{
				return true;
			}
		}
		else
		{
			if (ToEatPiece->isBlack && abs(dx) == 1 && dy == -1)
			{
				return true;
			}
		}
	}
	else
	{
		if (MovingPiece->isBlack)
		{
			if (dy == -1)
			{
				return true;
			}
			return false;
		}
		else
		{
			if (dy == 1)
			{
				return true;
			}
			return false;
		}
	}
  return false;*/
}
Pawn::~Pawn() {}
