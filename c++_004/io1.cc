 ///
 /// @file    io1.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-20 11:38:55
 ///

#include <iostream>

using std::cout;
using std::endl;

void printCin()
{
    std::cout << "bad = " << std::cin.bad() << std::endl;
    std::cout << "fail = " << std::cin.fail() << std::endl;
    std::cout << "eof = " << std::cin.eof() << std::endl;
    std::cout << "good = " << std::cin.good() << std::endl
    << std::endl;
}

int text(void)
{
    int inum;
    printCin();

    while(std::cin >> inum)
    {
        std::cout << inum << std::endl;
    }

    printCin();

    std::cin.clear();
    printCin();
    //std::cin.ignore(1024, '\n');

    std::string s;
    std::cin >> s;
    std::cout << s << std::endl;

    return 0;
}


int main()
{
	int ival;
	while(std::cin >> ival, !std::cin.eof())//c+d,cin over. c+c,finish run
	{
		if(std::cin.bad())
		{
			std::cout << "IO stream corrupted! " << std::endl;
			return -1;
		}
		if(std::cin.fail())
		{
			std::cout << "data illegal, try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			continue;
		}
		std::cout << "ival = " << ival << std::endl;
	}

	return 0;
}
