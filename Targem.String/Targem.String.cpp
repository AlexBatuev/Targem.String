#include <algorithm>
#include <iostream>
#include <vector>

#include "dstring.h"


int main()
{
    auto strings = std::vector<dstring>();

    std::cout << "String count:";
    size_t count;
    std::cin >> count;
	     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (count-- > 0)
	{
        dstring line;
        getline(std::cin, line);
				
        strings.push_back(std::move(line));
	}

    std::cout << std::endl;

    std::sort(std::begin(strings), std::end(strings));
    std::reverse(std::begin(strings), std::end(strings));
	
    for (auto& item : strings)
    {
        std::cout << item << '\n';
    }
}
