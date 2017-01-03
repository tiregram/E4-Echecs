#pragma once

#include "Helper.hpp"
#include "Iterator.hpp"
#include "Piece.hpp"

#include <iostream>
#include <map>
#include <memory>
#include <string>

class Plat {

  using Pie_ptr = std::shared_ptr<Piece>;
  std::map<std::string, Pie_ptr> pieces;

public:
  Plat() {

    pieces["e1"] = std::make_shared<King>(false, this);
    pieces["e8"] = std::make_shared<King>(true, this);

    pieces["d1"] = std::make_shared<Queen>(false, this);
    pieces["d8"] = std::make_shared<Queen>(true, this);
  }

  bool hasPieceAt(std::string position) {
    return this->pieces.find(position) != this->pieces.end();
  }

  void play(IteratorChessAction &ica) {
    for (auto &a : ica.actions) {
      std::cout <<"---------- " <<a.from << " to "<< a.to <<" ----------" << "\n";
      if (!this->hasPieceAt(a.from)) {
        throw "NO PIECE AT " + a.from;
      }

      auto p = getPieceAt(a.from);
      if (!p->check(a)) {
        throw "ACTION PROHIBITED " + a.from;
      }

      move(p, a);
      this->print();
    }
  }

  void move(std::shared_ptr<Piece> p, ChessAction a) {
    this->pieces.erase(a.from);
    this->pieces[a.to] = p;
  };

  Pie_ptr getPieceAt(std::string position) { return this->pieces[position]; }

  void print() {
    for (unsigned int i = 8; i > 0; i--) {

      for (unsigned int j = 1; j < 9; j++) {

        auto it = this->pieces.find(
            convertP2S(std::make_pair<int, int>(j, i))); // TODO

        if (it == this->pieces.end()) {
          std::cout << "X";
        } else {
          std::cout << it->second->getSymb();
        }
      }
      std::cout << "\n";
    }
  }
};
