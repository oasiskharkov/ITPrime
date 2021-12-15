#include "beautifulWordsCounter.h"

BeautifulWordsCounter::BeautifulWordsCounter() :
	m_counter{0ll}
{
	generator();
}

void BeautifulWordsCounter::generator()
{
	std::string number = firstNumber;
	while (true)
	{
		m_sums[getSum(number)]++;
		if (number == lastNumber)
		{
			break;
		}
		incrementNumber(number);
	}
}

void BeautifulWordsCounter::incrementNumber(std::string& str)
{
	for (int i = static_cast<int>(str.size()) - 1; i >= 0; --i)
	{
		int digit = getDigit(str[i]);
		if (digit != C)
		{
			str[i] = getChar(digit + 1);
			break;
		}
		else
		{
			str[i] = null;
		}
	}
}

int BeautifulWordsCounter::getSum(const std::string& number) const
{
	return std::accumulate(number.begin(), number.end(), 0, [this](int sum, const char ch) { return sum + this->getDigit(ch); });
}

__int64 BeautifulWordsCounter::count()
{
	for (const auto& p : m_sums)
	{
		m_counter += p.second * p.second;
	}
	return m_counter * digitsCount;
}

int BeautifulWordsCounter::getDigit(char digit) const
{
	if (::isdigit(digit))
	{
		return digit - null;
	}
	else if (digit == 'A')
	{
		return A;
	}
	else if (digit == 'B')
	{
		return B;
	}
	else if (digit == 'C')
	{
		return C;
	}
	throw std::logic_error("Unknown character: " + std::string{digit});
}

char BeautifulWordsCounter::getChar(int digit) const
{
	if (digit < A)
	{
		return static_cast<char>(digit + null);
	}
	else if (digit == A)
	{
		return 'A';
	}
	else if (digit == B)
	{
		return 'B';
	}
	else if (digit == C)
	{
		return 'C';
	}
	throw std::logic_error("Unknown digit : " + std::to_string(digit));
}
