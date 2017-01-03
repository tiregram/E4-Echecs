#pragma once
#include "ChessAction.hpp"
#include <vector>

class IteratorChessAction {
public:
  std::vector<ChessAction> actions;

  IteratorChessAction();

  void add(ChessAction& ca);

  virtual ~IteratorChessAction();
};
