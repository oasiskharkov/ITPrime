#include "beautifulWordCounter.h"

int main()
{
    try
    {
        BeautifulWordCounter bwc;
        std::string number;
        while (std::cin >> number)
        {
            bwc.checkNumber(number);
        }
        std::cout << "Beautiful words count: " << bwc.count() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
