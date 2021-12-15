#include "beautifulWordCounter.h"

BeautifulWordsCounter::BeautifulWordsCounter() :
	m_counter{0}
{
	generator();
}

void BeautifulWordsCounter::generator()
{
	std::string number = "000000";
	while (true)
	{
		m_sums[getSum(number)]++;
		if (number == "CCCCCC")
		{
			break;
		}
		increment(number);
	}
}

void BeautifulWordsCounter::increment(std::string& str)
{
	for (int i = static_cast<int>(str.size()) - 1; i >= 0; --i)
	{
		int digit = getDigit(str[i]);
		if (digit != 12)
		{
			str[i] = getChar(digit + 1);
			break;
		}
		else
		{
			str[i] = '0';
			continue;
		}
	}
}

int BeautifulWordsCounter::getSum(const std::string& number) const
{
	int sum = 0;
	std::for_each(number.begin(), number.end(), [this, &sum](const char ch) { sum += this->getDigit(ch); });
	return sum;
}

__int64 BeautifulWordsCounter::count()
{
	for (const auto& p : m_sums)
	{
		m_counter += p.second * p.second;
	}
	return m_counter * (partLength * 2 + 1);
}

int BeautifulWordsCounter::getDigit(char digit) const
{
	if (::isdigit(digit))
	{
		return digit - '0';
	}
	else if (digit == 'A')
	{
		return 10;
	}
	else if (digit == 'B')
	{
		return 11;
	}
	else if (digit == 'C')
	{
		return 12;
	}
	throw std::logic_error("Unknown digit: " + std::string{ digit });
}

char BeautifulWordsCounter::getChar(int digit) const
{
	if (digit < 10)
	{
		return static_cast<char>(digit + '0');
	}
	else if (digit == 10)
	{
		return 'A';
	}
	else if (digit == 11)
	{
		return 'B';
	}
	else if (digit == 12)
	{
		return 'C';
	}
	throw std::logic_error("Unknown digit : " + std::to_string(digit));
}
