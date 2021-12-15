#include "beautifulWordCounter.h"

BeautifulWordCounter::BeautifulWordCounter() :
	m_counter{0}
{
}

void BeautifulWordCounter::checkNumber(const std::string& number)
{
	std::string upper{ number };
	if (upper.length() != partLength * 2 + 1)
	{
		throw std::logic_error("Incorrect number length: " + upper);
	}
	std::transform(std::begin(number), std::end(number), upper.begin(), ::toupper);

	int sumLeft = 0;
	int sumRight = 0;
	for (int i = 0; i < partLength; ++i)
	{
		sumLeft += getDigit(upper[i]);
		sumRight += getDigit(upper[upper.length() - i - 1]);
	}

	if (sumLeft == sumRight)
	{
		++m_counter;
	}
}

int BeautifulWordCounter::count() const
{
	return m_counter;
}

int BeautifulWordCounter::getDigit(char digit) const
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
