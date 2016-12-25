#pragma once
#include <vector>

class Day7
{
public:
	Day7();
	~Day7();
	void parse(std::string& str);
	bool checkTls();
	bool checkNonTls();
	bool checkSslSequence();
	bool checkSslSequenceInBrackets();

private:
	std::string ssl_;

	std::vector<std::string> sequence_;
	std::vector<std::string> sequenceInBrackets_;
	static bool checkStringTls(const std::string& str);
	bool checkStringSsl(const std::string& str);
};

