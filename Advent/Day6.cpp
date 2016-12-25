#include "stdafx.h"
#include "Day6.h"
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>

void countOccurences(std::vector<char>& s, std::map<char, int>& histogram)
{
	for (const auto& c : s) { ++histogram[c]; }
}

char getMostCommonChar(std::map<char, int>& histogram)
{
	auto x = std::max_element(histogram.begin(), histogram.end(),
		[](const std::pair<char, int>& p1, const std::pair<char, int>& p2) {
		return p1.second < p2.second; });
	return x->first;
}

char getLeastCommonChar(std::map<char, int>& histogram)
{
	auto x = std::min_element(histogram.begin(), histogram.end(),
		[](const std::pair<char, int>& p1, const std::pair<char, int>& p2) {
		return p1.second < p2.second; });
	return x->first;
}
