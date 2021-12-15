#pragma once

#include <string>
#include <iostream>
#include <algorithm>

namespace 
{
	constexpr int partLength = 6;
}

class BeautifulWordCounter
{
public:
	BeautifulWordCounter();
	void checkNumber(const std::string& number);
	int count() const;
	int getDigit(char digit) const;
private:
	int m_counter;
};

