#include "Pawn.hpp"
#include <utility>
#include <math.h>

Pawn::Pawn(bool isBlack, Plat* pl) : Piece("Pawn", 'p', isBlack, pl) {}

bool Pawn::hasntMoved(const ChessAction &a)const
{
	std::pair<int, int> from = convertS2P(a.from);
	Plat::Pie_ptr MovingPiece = plate->getPieceAt(a.from);
	if (MovingPiece->isBlack)
	{
		return from.second == 7;
	}
	else
	{
		return from.second == 2;
	}
	return false;
}

bool Pawn::check(const ChessAction &a) const {
	std::pair<int, int> from = convertS2P(a.from);
	std::pair<int, int> to = convertS2P(a.to);
	
	Plat::Pie_ptr MovingPiece = plate->getPieceAt(a.from);

	int dx = to.first - from.first ;
	int dy = to.second - from.second;

	if (plate->getPieceAt(a.to))
	{
		Plat::Pie_ptr ToEatPiece = plate->getPieceAt(a.to);

		if (MovingPiece->isBlack)
		{
			if (!ToEatPiece->isBlack && abs(dx) == 1 && dy == -1)
			{
				// std::cout<< "1";
				return true;
				
			}
			// std::cout<< "2\n";
			return false;
		}
		else
		{
			if (ToEatPiece->isBlack && abs(dx) == 1 && dy == 1)
			{
				// std::cout<< "3\n";
				return true;
			}
			// std::cout<< "4\n";
			return false;
		}
	}
	else
	{
		if (MovingPiece->isBlack)
		{
			if (this->hasntMoved(a))
			{
				// std::cout<< "5\n";
				return ((dy == -1) || (dy == -2))&&(dx==0);
			}
			// std::cout<< "6\n";
			return dy == -1;
		}
		else
		{
			if (this->hasntMoved(a))
			{
				// std::cout<< "7\n";
				return ((dy == 1) || (dy == 2))&&(dx==0);
			}
			// std::cout<< "8\n";
			return dy == 1;
		}
	}
	// std::cout<< "9\n";
	return false;
}
Pawn::~Pawn() {}
