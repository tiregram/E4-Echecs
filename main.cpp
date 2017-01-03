
#include "ChessAction.hpp"
#include "Plat.hpp"
#include "Piece.hpp"

int main() {
  Plat pl;

  IteratorChessAction ica;
  auto a0 = ChessAction("a2", "a3");
  auto a0p = ChessAction("a7", "a6");
  auto a1 = ChessAction("e1", "e2");
  auto a2 = ChessAction("d8", "d5");
  auto a3 = ChessAction("a1", "a4");
  auto a4 = ChessAction("a8", "a4");

  ica.add(a0);
  ica.add(a0p);
  ica.add(a1);
  ica.add(a2);
  ica.add(a3);
  ica.add(a4);

  std::cout << "________START_______"  << "\n";
  pl.print();

  try {
    pl.play(ica);
  } catch (std::string a) {
    std::cout << a << "\n";
  }

  std::cout << "________END_______" << "\n";

  return 0;
}
