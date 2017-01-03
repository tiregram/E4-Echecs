
#include "Piece.hpp"



Piece::Piece(std::string p_name, char car, bool isBlack, Plat *p_pl)
  : name(p_name), car(car), isBlack(isBlack), plate(p_pl) {
  //  std::cout << "Creation:" << p_name << "\n";
}


char Piece::getSymb(){

  if (this->isBlack){
    return toupper(this->car);
  }
  else{
    return this->car;
  }
}

Piece::~Piece() {
  //std::cout << "Destruction:" << name << "\n";
}

bool Piece::TrajectoireLibre(std::string from, std::string to) const {
  std::pair<int, int> fromII = convertS2P(from);
  std::pair<int, int> toII = convertS2P(to);

  int moveOnX = toII.first - fromII.first;
  int moveOnY = toII.second - fromII.second;

  if (moveOnX != 0 && moveOnY != 0 && std::abs(moveOnY) != std::abs(moveOnX))
    return false;

  int move = std::abs(moveOnX == 0 ? moveOnY : moveOnX);

  for (int i = 1; i < move; i++) {
    std::pair<int, int> p = std::make_pair(fromII.first + i * sgn(moveOnX),
                                           fromII.second + i * sgn(moveOnY));

    if (this->plate->hasPieceAt(convertP2S(p))) {
      return false;
    }
  }
  return true;
}



