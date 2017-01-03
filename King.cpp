#include "King.hpp"
#include <utility>
#include <math.h>

King::King(bool isBlack, Plat* pl) : Piece("king", 'k', isBlack, pl) {}

bool King::check(const ChessAction &a) const {

	std::pair<int, int> fromII = convertS2P(a.from);
	std::pair<int, int> toII = convertS2P(a.to);

	Plat::Pie_ptr MovingPiece = plate->getPieceAt(a.from);
	Plat::Pie_ptr ToEatPiece;

	if (plate->getPieceAt(a.to)) {
		ToEatPiece = plate->getPieceAt(a.to);

		if (MovingPiece->isBlack == ToEatPiece->isBlack) {
			return false;
		}
	}

	int dx = fromII.first - toII.first;
	int dy = fromII.second - toII.second;

	if (sqrt(dx * dx + dy * dy) <= sqrt(2)) {
		return true;
	}
	return false;
}

King::~King() {}
