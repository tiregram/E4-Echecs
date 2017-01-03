#pragma once

#include <utility>
#include <string>

std::pair<int, int> convertS2P(std::string coord);
std::string convertP2S(std::pair<int, int> coord);
