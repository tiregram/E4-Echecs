#include "Iterator.hpp"

IteratorChessAction::IteratorChessAction() {
  
}

void IteratorChessAction::add(ChessAction& ca) {
 this->actions.push_back(ca);
}

IteratorChessAction::~IteratorChessAction() {
  
}
