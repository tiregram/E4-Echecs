#pragma once
#include <utility>
#include <string>

std::pair<int, int> convertS2P(std::string coord)
{
	char ltr = coord[0] - 'a' + 1;
	char nbr = coord[1] - '0';

	return std::pair<int, int>((int)ltr, (int)nbr);
}

std::string convertP2S(std::pair<int, int> coord)
{
	char ltr = static_cast<char>('a' + coord.first - 1);
	char nbr = static_cast<char>('0' + coord.second);
	std::string s; 
	s.push_back(ltr);
	s.push_back(nbr);
	return s;
}
