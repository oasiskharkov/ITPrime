#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>

namespace 
{
	constexpr int partLength = 6;
	constexpr int A = 10;
	constexpr int B = 11;
	constexpr int C = 12;
	constexpr char null = '0';
	constexpr int digitsCount = 13;
}

class BeautifulWordsCounter
{
public:
	BeautifulWordsCounter();
	__int64 count();
private:
	void generator();
	int getSum(const std::string& number) const;
	void incrementNumber(std::string& str);
	int getDigit(char digit) const;
	char getChar(int digit) const;
private:
	__int64 m_counter;
	std::map<int, __int64> m_sums;
};

