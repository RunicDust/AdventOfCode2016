#include "stdafx.h"
#include "Day3.h"
#include <sstream>
#include <algorithm>
#include <locale>


void Triangle::fillSides(std::string s)
{

	std::string token;
	std::stringstream stream(s);
	std::locale loc;
	sides_.clear();

	while (std::getline(stream, token, ' ')) {
		if (std::isdigit(token[0],loc))
			sides_.push_back(std::stoi(token));
	}

}

void Triangle::fillSides(std::vector<int> s)
{
	sides_.clear();
	for (auto &i : s) {
		sides_.push_back(i);
	}
}

bool Triangle::isRealTriangle()
{
	std::sort(sides_.begin(), sides_.begin() + 3);
	return ((sides_[0]+sides_[1])>sides_[2]);
}
