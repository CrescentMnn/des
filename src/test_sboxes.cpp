#include <iostream>
#include <bitset>

#include "encryption.h"

int main(){
    std::bitset<48> KDxorE{0b011100010001011100110010111000010101110011110000};
    auto s_out = s_function(KDxorE);
    
    std::cout << "KDxorE: " << KDxorE << std::endl;
    std::cout << "S = " << s_out << std::endl;

    return 0;
}
