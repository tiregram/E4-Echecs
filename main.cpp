
#include "ChessAction.hpp"
#include "Plat.hpp"

int main(int argc, char *argv[]) {
  Plat pl;

  IteratorChessAction ica;
  auto a1 = ChessAction("e1", "a2");
  auto a2 = ChessAction("d1", "a2");

  ica.add(a1);
  ica.add(a2);
  try {
    pl.play(ica);
  } catch (std::string a) {
    std::cout << a << "\n";
  }

  return 0;
}
