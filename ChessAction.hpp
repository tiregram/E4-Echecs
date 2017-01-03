#pragma once
#include <string>

class ChessAction
{
public:
  std::string from;
  std::string to;

  ChessAction(std::string p_f,std::string p_t):from(p_f),to(p_t){};
  ChessAction(std::string action):from(action.substr(0,2)),to(action.substr(3,2)){};

  virtual ~ChessAction(){};
};
