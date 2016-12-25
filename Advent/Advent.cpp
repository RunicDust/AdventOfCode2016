// Advent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <sstream>

std::string TextFileToString(std::string filename)
{
	std::ostringstream dosString(std::ios::out | std::ios::binary); // *** binary
	std::ifstream inFile(filename.c_str());

	std::string line;
	while (std::getline(inFile, line)) dosString << line << "\r\n";

	return dosString.str();
}


/*
int main()
{
	std::vector<std::string> vec;
	std::string token;

	std::string ss = TextFileToString("input_day1.txt");

	ss.erase(std::remove(ss.begin(), ss.end(), ','), ss.end());

	std::stringstream stream(ss);

	while (std::getline(stream, token, ' ')) {
		vec.push_back(token);
	}

	//Position p;
	//p.turn(vec[0]);
	
	//std::cout << p.angle_ << std::endl;


	return 0;
}

*/