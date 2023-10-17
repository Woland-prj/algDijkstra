#include <iostream>
#include "StrToPostfix.h"

int main(
    
)
{
    std::setlocale(LC_ALL, "ru");
    CStrToPostfix sp;
    if (argc != 2) {
        std::cout << "There is no expression as the first argument" << std::endl;
        exit(1);
    }
    std::cout << sp.strToPostfix(argv[1]) << std::endl;
}
