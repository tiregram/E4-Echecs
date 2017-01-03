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
