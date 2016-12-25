#include "stdafx.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>


struct Point {
	int x=0;
	int y=0;
};



class Position {
public:
	Point p_;
	int angle_=90;
	std::vector<std::string> trace;

public:
	void turn(std::string s)
	{
		auto direction = s[0];

		switch (direction)
		{
		case('R'):
			angle_ -= 90;
			break;
		case('L'):
			angle_ += 90;
		default:
			break;
		}
	}
	void move(std::string s) {
		s.erase(0,1);
		int steps = stoi(s);
		angle_ = angle_ % 360;


		int angle = angle_;

		if (angle_ < 0)
		{
			angle = 360 + angle_;
		}

		switch (angle)
		{
		case(0):
			for (int i = 1; i <= steps; i++)
			{
				auto x = p_.x + i;
				trace.push_back(std::to_string(x) + " " + std::to_string(p_.y));
			}
			
			p_.x += steps;
			
			break;
		case(90):
			
			for (int i = 1; i <= steps; i++)
			{
				auto y = p_.y + i;
				trace.push_back(std::to_string(p_.x) + " " + std::to_string(y));
			}

			p_.y += steps;
			break;

		case(180):
			for (int i = 1; i <= steps; i++)
			{
				auto x = p_.x - i;
				trace.push_back(std::to_string(x) + " " + std::to_string(p_.y));
			}

			p_.x -= steps;
			break;
		case(270):
			for (int i = 1; i <= steps; i++)
			{
				auto y = p_.y - i;
				trace.push_back(std::to_string(p_.x) + " " + std::to_string(y));
			}

			p_.y -= steps;
			break;

		default:
			break;
		}


	}

};


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
	std::vector<std::string> moves;
	std::string token;

	std::string ss = TextFileToString("input_day1.txt");

	//std::string ss = "R8, R4, R4, R8";

	ss.erase(std::remove(ss.begin(), ss.end(), ','), ss.end());

	std::stringstream stream(ss);

	while (std::getline(stream, token, ' ')) {
		moves.push_back(token);
	}



	Position p;
	std::vector<std::string> uniqueTrace;
	p.trace.push_back("0 0");

	for each (auto m in moves)
	{
		p.turn(m);
		p.move(m);
		uniqueTrace=p.trace;
	}
	
	std::set<std::string> occurrences;

	int sum = 0;

	for (std::vector<std::string>::const_iterator cit = uniqueTrace.begin(); cit != uniqueTrace.end(); ++cit) {
		if (false == occurrences.insert(*cit).second) {
			std::cout << *cit<<std::endl;
			std::stringstream stream2(*cit);
			while (std::getline(stream2, token, ' ')) {
				sum+= abs(stoi(token));
			}
				break;
		}
			
	}
		


	auto blocksAway = abs(p.p_.x) + abs(p.p_.y);
	std::cout << blocksAway << std::endl;
	std::cout << sum << std::endl;
	



	return 0;
}
*/

