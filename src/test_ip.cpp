#include <iostream>
#include <bitset>

/* User Headers */
#include "ip.h"

int main(){

    std::bitset<64> ip_in{0b0000000100100011010001010110011110001001101010111100110111101111};

    auto ip_out = ip_function(ip_in);

    std::bitset<64> ip_inv_in{0b1111101100100001111110111001110010111010100010001111011010011001};

    auto ip_inv_out = ip_inv_function(ip_inv_in);

    std::cout << "IP: " << ip_out << std::endl;

    std::cout << "IP inv: " << ip_inv_out << std::endl;

    return 0;
}
