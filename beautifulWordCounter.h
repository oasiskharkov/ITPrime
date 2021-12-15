#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <numeric>

namespace 
{
	constexpr int partLength = 6;
}

class BeautifulWordsCounter
{
public:
	BeautifulWordsCounter();
	void generator();
	int getSum(const std::string& number) const;
	void increment(std::string& str);
	__int64 count();
	int getDigit(char digit) const;
	char getChar(int digit) const;
private:
	__int64 m_counter;
	std::map<int, __int64> m_sums;
};

