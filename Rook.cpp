#include "Rook.hpp"
#include <utility>
#include <math.h>

Rook::Rook(bool isBlack, Plat* pl) : Piece("Rook", 'r', isBlack, pl) {}

bool Rook::check(const ChessAction &a) const {
	std::pair<int, int> from = convertS2P(a.from);
	std::pair<int, int> to = convertS2P(a.to);

	Plat::Pie_ptr MovingPiece = plate->getPieceAt(a.from);
	Plat::Pie_ptr ToEatPiece;

	if (plate->getPieceAt(a.to)) {
		ToEatPiece = plate->getPieceAt(a.to);

		if (MovingPiece->isBlack == ToEatPiece->isBlack) {
			return false;
		}
	}

	int dx = from.first - to.first;
	int dy = from.second - to.second;

	if (dx == 0 || dy == 0) 
	{
		if (not TrajectoireLibre(a.from, a.to)) {
			return false;
		}
		return true;
	}
	return false;
}
Rook::~Rook() {}