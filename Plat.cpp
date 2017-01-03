#include "Plat.hpp"
#include "King.hpp"
#include "Piece.hpp"
#include "Queen.hpp"
#include <utility>

#include "Bishop.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"

Plat::Plat() {

  // pawn
  pieces["a2"] = std::make_shared<Pawn>(false, this);
  pieces["a7"] = std::make_shared<Pawn>(true, this);
  pieces["b2"] = std::make_shared<Pawn>(false, this);
  pieces["b7"] = std::make_shared<Pawn>(true, this);
  pieces["c2"] = std::make_shared<Pawn>(false, this);
  pieces["c7"] = std::make_shared<Pawn>(true, this);
  pieces["d2"] = std::make_shared<Pawn>(false, this);
  pieces["d7"] = std::make_shared<Pawn>(true, this);
  pieces["e2"] = std::make_shared<Pawn>(false, this);
  pieces["e7"] = std::make_shared<Pawn>(true, this);
  pieces["f2"] = std::make_shared<Pawn>(false, this);
  pieces["f7"] = std::make_shared<Pawn>(true, this);
  pieces["g2"] = std::make_shared<Pawn>(false, this);
  pieces["g7"] = std::make_shared<Pawn>(true, this);
  pieces["h2"] = std::make_shared<Pawn>(false, this);
  pieces["h7"] = std::make_shared<Pawn>(true, this);

  // Bishop
  pieces["c1"] = std::make_shared<Bishop>(false, this);
  pieces["c8"] = std::make_shared<Bishop>(true, this);

  pieces["f1"] = std::make_shared<Bishop>(false, this);
  pieces["f8"] = std::make_shared<Bishop>(true, this);

  // knight
  pieces["b1"] = std::make_shared<Knight>(false, this);
  pieces["b8"] = std::make_shared<Knight>(true, this);

  pieces["g1"] = std::make_shared<Knight>(false, this);
  pieces["g8"] = std::make_shared<Knight>(true, this);

  // tour
  pieces["a1"] = std::make_shared<Rook>(false, this);
  pieces["a8"] = std::make_shared<Rook>(true, this);

  pieces["h1"] = std::make_shared<Rook>(false, this);
  pieces["h8"] = std::make_shared<Rook>(true, this);

  // king
  pieces["e1"] = std::make_shared<King>(false, this);
  pieces["e8"] = std::make_shared<King>(true, this);

  // queen
  pieces["d1"] = std::make_shared<Queen>(false, this);
  pieces["d8"] = std::make_shared<Queen>(true, this);
}

bool Plat::hasPieceAt(std::string position) {
  return this->pieces.find(position) != this->pieces.end();
}

void Plat::print() {
  for (unsigned int i = 8; i > 0; i--) {

    for (unsigned int j = 1; j < 9; j++) {

      auto it =
          this->pieces.find(convertP2S(std::make_pair<int, int>(j, i))); // TODO

      if (it == this->pieces.end()) {
        std::cout << "x";
      } else {
        std::cout << it->second->getSymb();
      }
    }
    std::cout << "\n";
  }
}

void Plat::play(IteratorChessAction &ica) {

  bool whiteTurn = true;

  for (auto &a : ica.actions) {
    //    std::cout << " __________ " << (whiteTurn ? "WHITE" : "BLACK")
    //         << " __________"
    //          << "\n";
    // std::cout << "---------- " << a.from << " to " << a.to << " ----------"
    //          << "\n";
    if (!this->hasPieceAt(a.from)) {
      //throw "NO PIECE AT " + a.from;
      std::cout << a.l << "\n";
      std::abort();
    }

    auto p = getPieceAt(a.from);

    if (p->isBlack && whiteTurn) {
      //throw "White try to play black from " + a.from + " to " + a.to;
      std::cout << a.l << "\n";
      std::abort();
    }

    if (not p->isBlack && not whiteTurn) {
      //throw "White try to play black from " + a.from + " to " + a.to;
      std::cout << a.l << "\n";
      std::abort();
    }

    if (!p->check(a)) {
      //throw "ACTION PROHIBITED " + a.from + " to " + a.to;
      std::cout << a.l << "\n";
      std::abort();
    }

    move(p, a);
    //    this->print();
    whiteTurn = !whiteTurn;
  }
}

void Plat::move(std::shared_ptr<Piece> p, ChessAction a) {
  this->pieces.erase(a.from);
  this->pieces[a.to] = p;
}

Plat::Pie_ptr Plat::getPieceAt(std::string position) {
  return this->pieces[position];
}
