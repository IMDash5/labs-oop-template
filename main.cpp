#include "src/Hex.cpp"


#include <iostream>
#include <string>


int main(){
    unsigned char digit = 'A';
    int decimal = hexToDecimal(digit);
    std::cout << decimal << std::endl;
    unsigned char hex = decimalToHex(decimal);
    std::cout << hex << std::endl;

    std::cout << "---------------------------------------------------------------" << std::endl;

    std::string testString1;
    std::string testString2;

    std::cout << "Введите первое число: "<< std::endl;
    std::cin >> testString1;

    std::cout << "Введите второе число: "<< std::endl;
    std::cin >> testString2;


    Hex stringInputShow1(testString1);
    Hex stringInputShow2(testString2);

    std::cout << stringInputShow1.getData() << std::endl;
    std::cout << stringInputShow1.getSize() << std::endl;

    std::cout << stringInputShow2.getData() << std::endl;
    std::cout << stringInputShow2.getSize() << std::endl;
    
    
    stringInputShow1 += stringInputShow2;

    std::cout << stringInputShow1.getData() << std::endl;
    

    return 0;
}