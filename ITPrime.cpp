#include "beautifulWordsCounter.h"

int main()
{
    try
    {
        BeautifulWordsCounter bwc;
        std::cout << "Beautiful words count: " << bwc.count() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}