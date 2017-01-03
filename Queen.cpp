#include "Queen.hpp"
#include <utility>
#include <math.h>

Queen::Queen(bool isBlack, Plat* pl) : Piece("Queen", 'q', isBlack, pl) {}

bool Queen::check(const ChessAction &a) const {
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

	if ((std::abs(dx) == std::abs(dy)) || (dx == 0 || dy == 0)) {
		if (!TrajectoireLibre(a.from, a.to)) {
      			return false;
		}
		return true;
	}
	return false;
}
Queen::~Queen() {}
