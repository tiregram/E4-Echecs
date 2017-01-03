#pragma once

#include "Plat.hpp"
#include "ChessAction.hpp"
#include "Helper.hpp"
#include <iostream>
#include <math.h>
#include <memory>
#include <string>

class Piece {

public:
  std::string name;
  char car;
  bool isBlack;
  Plat * plate;

  template <typename T> int sgn(T val) const {
    return (T(0) < val) - (val < T(0));
  }

  bool TrajectoireLibre(std::string from, std::string to) const;

  Piece(std::string p_name, char car, bool isBlack, Plat *p_pl);

  virtual char getSymb();
  virtual bool check(const ChessAction &a) const = 0;

  virtual ~Piece();
};


/*


class King : public Piece {
public:
  King(bool isBlack, Plat *pl) : Piece("king", 'k', isBlack, pl) {}
  virtual bool check(const ChessAction &a) const { return true; };
  virtual ~King() {}
};

class Queen : public Piece {
public:
  Queen(bool isBlack, Plat *pl) : Piece("Queen", 'q', isBlack, pl) {}
  virtual bool check(const ChessAction &a) const { return true; };
  virtual ~Queen() {}
};
*/
/*
class King : public Piece {
public:
  King(bool isBlack,Plat* pl) : Piece("king", 'k', isBlack,pl) {}
  virtual bool check(const ChessAction &a) const {
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

    int dx = fromII.first - toII.second;
    int dy = fromII.second - toII.second;

    if (std::sqrt(dx * dx + dy * dy) <= std::sqrt(2)) {
      return true;
    }
    return false;
  }
  virtual ~King() {}
};

class Queen : public Piece {
public:
  Queen(bool isBlack,Plat* pl) : Piece("Queen", 'q', isBlack,pl) {}
  virtual bool check(const ChessAction &a) const {
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

    int dx = from.first - to.second;
    int dy = from.second - to.second;

    if ((std::abs(dx) == std::abs(dy)) || (dx == 0 || dy == 0)) {
      if (TrajectoireLibre(a.from, a.to)) {
        return false;
      }
      return true;
    }
    return false;
  }
  virtual ~Queen() {}
};

class Rook : public Piece {
public:
  Rook(bool isBlack,Plat * pl) : Piece("Rook", 'r', isBlack,pl) {}
  virtual bool check(const ChessAction &a) const {
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

    int dx = from.first - to.second;
    int dy = from.second - to.second;

    if (dx == 0 || dy == 0) {
      if (TrajectoireLibre(a.from, a.to)) {
        return false;
      }
      return true;
    }
    return false;
  }
  virtual ~Rook() {}
};

class Bishop : public Piece {
public:
  Bishop(bool isBlack,Plat * pl) : Piece("Bishop", 'b', isBlack,pl) {}
  virtual bool check(const ChessAction &a) const {
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

    int dx = from.first - to.second;
    int dy = from.second - to.second;

    if (std::abs(dx) == std::abs(dy)) {
      if (TrajectoireLibre(a.from, a.to)) {
        return false;
      }
      return true;
    }
    return false;
  }
  virtual ~Bishop() {}
};

class Knight : public Piece {
public:
  Knight(bool isBlack,Plat * pl) : Piece("Knight", 'k', isBlack,pl) {}
  virtual bool check(const ChessAction &a) const {
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

    int dx = from.first - to.second;
    int dy = from.second - to.second;

    if ((std::abs(dx) == 2 && std::abs(dy) == 1) ||
        (std::abs(dx) == 1 && std::abs(dy) == 2)) {
      return true;
    }
    return false;
  }
  virtual ~Knight() {}
};
*/
