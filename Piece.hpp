#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "ChessAction.hpp"

class Plat;

class Piece {

public:
  std::string name;
  char car;
  bool isBlack;

  Plat* pl;

  Piece(std::string p_name, char car, bool isBlack,Plat* p_pl)
    : name(p_name), car(car), isBlack(isBlack),pl(p_pl)
  {
    std::cout << "Creation:" << p_name << "\n";
  }

  virtual char getSymb() {
    if (this->isBlack)
      return toupper(this->car);
    else
      return this->car;
  }

  virtual bool check(const ChessAction& a) const = 0;

  virtual ~Piece() { std::cout << "Destruction:" << name << "\n"; }
};

class King : public Piece {
public:
  King(bool isBlack,Plat* pl) : Piece("king", 'k', isBlack, pl) {}
  virtual bool check(const ChessAction& a) const {return true;};
  virtual ~King() {}
};

class Queen : public Piece {
public:
  Queen(bool isBlack,Plat* pl) : Piece("Queen", 'q', isBlack, pl) {}
  virtual bool check(const ChessAction& a) const {return true;};
  virtual ~Queen() {}
};
