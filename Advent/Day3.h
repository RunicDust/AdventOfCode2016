#pragma once
#include <string>
#include <vector>

class Triangle
{
public:
	void fillSides(std::string s);
	void fillSides(std::vector<int> s);
	bool isRealTriangle();
private:
	std::vector<int> sides_;
};


