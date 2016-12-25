#pragma once
#include <vector>
#include <map>

void countOccurences(std::vector<char>& s, std::map<char, int>& histogram);
char getMostCommonChar(std::map<char, int>& histogram);
char getLeastCommonChar(std::map<char, int>& histogram);