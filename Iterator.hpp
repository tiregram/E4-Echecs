#pragma once
#include "ChessAction.hpp"
#include <vector>
#include <string>

class IteratorChessAction {
public:
  std::vector<ChessAction> actions;

  IteratorChessAction();
  IteratorChessAction( std::string nameFile );

  void add(ChessAction& ca);
  void add(std::string action);
  virtual ~IteratorChessAction();
};
