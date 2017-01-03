#include "Iterator.hpp"
#include <fstream>
#include <iostream>
IteratorChessAction::IteratorChessAction() {}

IteratorChessAction::IteratorChessAction(std::string nameFile) {
  std::ifstream filechess(nameFile);
  std::string line;
  int i = 1;

  while (std::getline(filechess, line)) {
    add(i++,line);
    // std::cout << " ->" << line << "\n";
  }
  filechess.close();
}

void IteratorChessAction::add(ChessAction &ca) { this->actions.push_back(ca); }

void IteratorChessAction::add(int l, std::string action) {
  this->actions.push_back(ChessAction(l,action));
}

IteratorChessAction::~IteratorChessAction() {}
