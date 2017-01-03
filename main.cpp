
#include "ChessAction.hpp"
#include "Piece.hpp"
#include "Plat.hpp"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cout<< "no file"<< std::endl;
    return 1;
  }
  Plat pl;
  IteratorChessAction ica(argv[1]);

  //  std::cout << "________START_______"
  //         << "\n";

  try {
    pl.play(ica);
  } catch (std::string a) {
    std::cout << a << "\n";
  }
  pl.print();
  //  std::cout << "________END_______"
  //        << "\n";

  return 0;
}
