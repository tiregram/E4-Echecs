#pragma once

#include "Helper.hpp"
#include "Iterator.hpp"

#include <iostream>
#include <map>
#include <memory>
#include <string>

class Piece;

class Plat {


public:
  using Pie_ptr = std::shared_ptr<Piece>;
  std::map<std::string, Pie_ptr> pieces;
  Plat();

  bool hasPieceAt(std::string position);

  void play(IteratorChessAction &ica);

  void move(std::shared_ptr<Piece> p, ChessAction a);

  Pie_ptr getPieceAt(std::string position);

  void print();

};
