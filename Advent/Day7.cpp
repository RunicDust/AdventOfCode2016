#include "stdafx.h"
#include "Day7.h"
#include <iostream>


Day7::Day7()
{
}


Day7::~Day7()
{
}

void Day7::parse(std::string& str)
{
	unsigned first;
	unsigned last;

	sequence_.clear();
	sequenceInBrackets_.clear();
	while(true){

	first=str.find('[');
	last = str.find(']');


	if(last != std::string::npos)
	{
		sequence_.push_back(str.substr(0, first));
		sequenceInBrackets_.push_back(str.substr(first + 1, last - first - 1));
		str.erase(str.begin(), str.begin() + last + 1);
	}
	else
	{
		sequence_.push_back(str);
		break;
	}
	}
}

bool Day7::checkStringTls(const std::string& str)
{
	for (auto i=1; i<str.size();i++)
	{
		if ((str[i]==str[i+1])&&(str[i-1] == str[i + 2])&& (str[i - 1] != str[i]))
		{
			return true;
		}
	}
	return false;
}

bool Day7::checkStringSsl(const std::string& str)
{
	for (auto i = 1; i < str.size(); i++)
	{
		if ((str[i - 1] == str[i + 1]) && (str[i - 1] != str[i]))
		{
			ssl_.clear();
			ssl_.push_back(str[i]);
			ssl_.push_back(str[i - 1]);
			ssl_.push_back(str[i]);
			if (checkSslSequenceInBrackets())
			{
				return true;
			}
			if ((i + 1) != str.size())
				{
					ssl_.clear();
					auto subStr = str.substr(i, str.size() - i);
					checkStringSsl(subStr);
				}
		}
	}
	return false;
}

bool Day7::checkTls()
{
	for (auto s: sequence_)
	{
		if (checkStringTls(s))
		{
			return true;
		}
	}
	return false;
}

bool Day7::checkNonTls()
{
	for (auto s : sequenceInBrackets_)
	{
		if (checkStringTls(s))
		{
			return false;
		}
	}
	return true;
}

bool Day7::checkSslSequence()
{
	for (auto s : sequence_)
	{
		if (checkStringSsl(s))
		{
			return true;
		}
	}
	return false;
}

bool Day7::checkSslSequenceInBrackets()
{
	for (auto s : sequenceInBrackets_)	
	{
		auto found = s.find(ssl_);
		if (found != std::string::npos)
		{
			return true;
		}
	}
	return false;
}
