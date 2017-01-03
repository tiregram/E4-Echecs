#include "Knight.hpp"
#include <utility>
#include <math.h>

Knight::Knight(bool isBlack, Plat* pl) : Piece("Knight", 'n', isBlack, pl) {}

bool Knight::check(const ChessAction &a) const {
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

	if ((std::abs(dx) == 2 && std::abs(dy) == 1) || (std::abs(dx) == 1 && std::abs(dy) == 2))
	{
		return true;
	}
	return false;
}
Knight::~Knight() {}
