#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include "md5.h"
#include "Day6.h"
#include <regex>
#include "Day7.h"

bool isSameChar(char a, char b) { return a==b; }

// Day3
void readColumns(std::string filename, int columnNo, std::vector <int>& column)
{
	auto colNum = 3;
	std::vector<std::vector <int> > data;
	std::ifstream ifile(filename.c_str());

	if (ifile.is_open()) {
		int num;
		std::vector <int> numbersInLine;

		while (ifile >> num) {
			numbersInLine.push_back(num);

			if (numbersInLine.size() == colNum) {
				data.push_back(numbersInLine);
				numbersInLine.clear();
			}
		}
	}

	for (auto i = 0; i < data.size(); ++i) {
		column.push_back(data[i][columnNo - 1]);
	}

	ifile.close();
}

// Day 6

void readCharColumns(std::string filename, int columnNo, std::vector<char>& column)
{
	auto colNum = 8;
	std::vector<std::vector<char> > data;
	std::ifstream ifile(filename.c_str());

	if (ifile.is_open()) {
		char ch;
		std::vector <char> numbersInLine;

		while (ifile >> ch) {
			numbersInLine.push_back(ch);

			if (numbersInLine.size() == colNum) {
				data.push_back(numbersInLine);
				numbersInLine.clear();
			}
		}
	}

	for (auto i = 0; i < data.size(); ++i) {
		column.push_back(data[i][columnNo - 1]);
	}

	ifile.close();
}


int main(int argc, char* argv[])
{
///////////////////     Day 2

/*	std::ifstream file("input_day2.txt");
	std::vector<std::string> input;

	for (std::string line; getline(file, line); )
	{
		input.push_back(line);
	}

	Board b;

	for (auto s:input)
	{
		for(auto i=0; i<s.length();i++)
		{
			b.makeStep(s[i]);
		}
	}

	
	Board2 b2;

	for (auto s : input)
	{
		for (auto i = 0; i<s.length(); i++)
		{
			b2.makeStep(s[i]);
		}
		std::cout << b2.getButton() << std::endl;
	}*/

///////////////////     Day 3

/*
 * 	std::ifstream file("input_day3.txt");
	std::string s;
	Triangle t;
	auto sum = 0;

	for (std::string line; getline(file, s); )
	{
		t.fillSides(s);
		if (t.isRealTriangle())
		{
			sum += 1;
		}

	}


	//  Part 2  
	std::vector <int> columnVector;
	readColumns("input_day3.txt", 1, columnVector);
	readColumns("input_day3.txt", 2, columnVector);
	readColumns("input_day3.txt", 3, columnVector);

	Triangle t;
	std::vector<int> sides;

	auto sum = 0;

	for (auto i = 0; i <= columnVector.size()-3; i=i+3) {
		sides.clear();
		sides.push_back(columnVector[i]);
		sides.push_back(columnVector[i+1]);
		sides.push_back(columnVector[i+2]);
		t.fillSides(sides);
		if (t.isRealTriangle())
		{
			sum += 1;
		}

	}
	
	std::cout << sum;
*/

///////////////////     Day 4

/*  std::ifstream file("input_day4.txt");
  std::vector<std::string> input;
  auto sum = 0;

  for (std::string line; getline(file, line); )
  {
     input.push_back(line);
  }

  for(auto& s:input){
  
	std::vector<std::string> encryptedRoomName;
	
	std::string checksum;
	int id;

	parseInTokens(s, encryptedRoomName);

	auto roomInfo = encryptedRoomName[encryptedRoomName.size() - 1];
	getIdandChecksum(roomInfo, checksum,id);
	encryptedRoomName.pop_back();

	// Convert vector to string
	std::string str;
	str = accumulate(begin(encryptedRoomName), end(encryptedRoomName), str);


	Room r(str, checksum, id);

	  if (r.isReal())
	  {
		  sum += id;

	  }
	
  }*/

  // Part 2

/*std::ifstream file("input_day4.txt");
std::vector<std::string> input;

for (std::string line; getline(file, line); )
{
	input.push_back(line);
}

for (auto& s : input) {

	std::vector<std::string> encryptedRoomName;

	std::string checksum;
	int id;

	parseInTokens(s, encryptedRoomName);

	auto roomInfo = encryptedRoomName[encryptedRoomName.size() - 1];
	getIdandChecksum(roomInfo, checksum, id);
	encryptedRoomName.pop_back();

	// Convert vector to string
	std::ostringstream ss;

	for (auto token : encryptedRoomName)
	{
		ss << token << "-";
	}

	auto str = ss.str();
	str = str.substr(0, str.size() - 1);

	Room r(str, checksum, id);
	r.decryptRoomName();

	if (r.decodedName_== "northpole object storage")
	{
		std::cout << r.sectorId_ << std::endl;
		break;
	}

}*/


///////////////////     Day 5


/*auto i = 0;
std::vector<std::string> hashVec;

auto part1 = 0;
auto part2 = 1;

std::vector<int> check(8); 
std::iota(std::begin(check), std::end(check), 0);


while(true)
{
	auto str = "cxdnnyjw"+std::to_string(i);
	
	MD5 md5 = MD5(str);
	auto hash = md5.getDigest();

	if( hash.substr(0, 5) == "00000")
	{
		std::cout << hash << std::endl;

		if (part1==1)
		{
			hashVec.push_back(hash);
			if (hashVec.size()==8)
			break;
		}

		if (part2==1)
		{
			auto h = hash[5] - '0';
			if (h>= 0 && h<=7)
			{		
				if (std::find(check.begin(), check.end(), h) != check.end())
				{
					hashVec.push_back(hash);
					std::cout << hashVec.size() << std::endl;
					check[h]=8;
					if (hashVec.size() == 8)
						break;
				}

			}
			
		}

	}

	i++;
}


std::string password;
	if (part1==1)
	{
		for (auto h : hashVec)
		{
			password += h[5];
		}
		std::cout << " " << std::endl;
		std::cout << "PASSWORD     " << password<< std::endl;
	}
	

char pass[8];
	if (part2==1)
	{
		for (auto h : hashVec)
		{
			std::cout << h[5] << " " << h[6] << std::endl;
			auto index = h[5] - '0';
			pass[index] = h[6];
		}
		std::cout << " " << std::endl;
		std::cout << "PASSWORD     " << pass<< std::endl;
	}*/

///////////////////     Day 6

/*std::string s;
bool part1 = 0;
bool part2 = 1;

for (auto i = 1; i < 9; i++) {
	std::vector<char> column;
	readCharColumns("input_day6.txt", i, column);

	std::map<char, int> histogram;
	countOccurences(column, histogram);
	char c=0;

	if(part1)
	{
		c = getMostCommonChar(histogram);
	}
	
	if(part2)
	{
		c = getLeastCommonChar(histogram);
	}
	
	std::cout << c<<std::endl;
	s.push_back(c);
}

std::cout << s << std::endl;*/

///////////////////     Day 7
Day7 d;

std::ifstream file("input_day7.txt");
auto sum=0;
bool result;

for (std::string line; getline(file, line); )
{
	d.parse(line);
//	result=d.checkTls()&& d.checkNonTls();
//
//	if (result)
//	{
//		sum += 1;
//	}

	result=d.checkSslSequence()&& d.checkSslSequenceInBrackets();

	if (result)
	{
		sum += 1;
	}


}

std::cout << sum << std::endl;



return 0;
}

