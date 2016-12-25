#include "stdafx.h"
#include "Day4.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iterator>

void parseInTokens(std::string s, std::vector<std::string>& encryptedRoomName)
{

	std::string token;

	std::stringstream stream(s);

	while (std::getline(stream, token, '-')) {
		encryptedRoomName.push_back(token);
	}
}

void getIdandChecksum(std::string& idAndChecksum, std::string& id, int& checksum)
{
	std::stringstream stream(idAndChecksum);
	std::vector<std::string> aux;
	std::string token;
	while (std::getline(stream, token, '[')) {
		aux.push_back(token);
	}

	checksum = std::stoi(aux[0]);
	id = aux[1];
	id.pop_back();
}


Room::Room(std::string& row, std::string& checksum, int sectorId)
	: encodedName_(row),
	checksum_(checksum),
	sectorId_(sectorId)
{

}

bool cmpPair(std::pair<int, char> i, std::pair<int, char> j)
{

	if (j.first > i.first) return false;
	if (j.first < i.first) return true;

	return i.second < j.second;
}


bool Room::isReal()
{
	std::sort(encodedName_.begin(), encodedName_.end());
	//std::vector<int> charNo;

	std::vector<std::pair<int, char>> charNo;

	for (auto i=0; i< checksum_.size();i++)
	{
		auto n = std::count(encodedName_.begin(), encodedName_.end(), checksum_[i]);
		 std::pair<int, char> p(n, checksum_[i]);
		charNo.push_back(p);		
	}

	std::sort(charNo.begin(), charNo.end(), cmpPair);
	auto i = std::find_if(charNo.begin(), charNo.end(),
		[](const std::pair<int, char>& element) { return element.first == 0; });

	if (i != charNo.end())
	{
		return false;
	}
	

	std::stringstream generatedChecksumStream;
	std::string generatedChecksum;

	for (auto it = charNo.begin(); it != charNo.end(); ++it)
	{
		generatedChecksumStream << it->second;
	}

	generatedChecksum=generatedChecksumStream.str();

	if (generatedChecksum.find(checksum_) != std::string::npos) {

		return true;
	}

	return false;
}

void shift(char& ch, int& key)
{
	for(auto i = 0; i < key; i++){
	if (ch == 'z')	{ch = 'a';}
	else { ch += 1; }	
	}

}


void Room::decryptRoomName()
{
	std::vector<std::string> encryptedRoomName;
	parseInTokens(encodedName_, encryptedRoomName);
	auto key = sectorId_%26;

	for (auto& token : encryptedRoomName)
	{
		for (auto i = 0; i < token.length(); i++){
			shift(token[i], key);
		}
	}

	// convert vector to string
	std::ostringstream ss;

	for (auto token : encryptedRoomName)
	{
		ss << token<<" ";
	}

	auto decryptedName = ss.str();

	decryptedName= decryptedName.substr(0, decryptedName.size() - 1);
	decodedName_ = decryptedName;
}
