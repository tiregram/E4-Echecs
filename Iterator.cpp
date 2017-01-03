#include "Iterator.hpp"
#include <fstream>
#include <iostream>
IteratorChessAction::IteratorChessAction() {}

IteratorChessAction::IteratorChessAction(std::string nameFile) {
  std::ifstream filechess(nameFile);
  std::string line;

  while (std::getline(filechess, line)) {
    add(line);
    // std::cout << " ->" << line << "\n";
  }
  filechess.close();
}

void IteratorChessAction::add(ChessAction &ca) { this->actions.push_back(ca); }

void IteratorChessAction::add(std::string action) {
  this->actions.push_back(ChessAction(action));
}

IteratorChessAction::~IteratorChessAction() {}
