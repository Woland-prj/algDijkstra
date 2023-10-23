#include <iostream>
#include <fstream>
#include "StrToPostfix.h"

int main()
{
    CStrToPostfix sp;
    std::string line;
    std::ifstream inputFile("in.txt");
    if (inputFile.is_open())
    {
        while (std::getline(inputFile, line))
        {
            std::cout << "Infix form: " << line << std::endl;
            std::cout << "Postfix form: " << sp.strToPostfix(line) << std::endl << std::endl;
        }
    }
    else {
        std::cout << "Can not open file in.txt" << std::endl;
        exit(1);
    }
    inputFile.close();
}
