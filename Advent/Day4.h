#pragma once
#include <string>
#include <vector>

void parseInTokens(std::string s, std::vector<std::string>& encryptedRoomName);
void getIdandChecksum(std::string& encryptedRoomName, std::string& id, int& checksum);

class Room
{
public:
	Room(std::string& basic_strings, std::string& sector_id, int checksum);
	bool isReal();
	void decryptRoomName();

	std::string encodedName_;
	std::string decodedName_;
	std::string checksum_;
	int sectorId_;
};
