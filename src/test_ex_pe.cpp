#include <iostream>
#include <bitset>
#include "encryption.h"

int main(){
    std::bitset<32> r0{0b11110000101010101111000010101010};
    std::bitset<32> l0{0b11001100000000001100110011111111};
    std::bitset<48> key{0b000010110000001001100111100110110100100110100101};
    
    auto exp = expansion_function(r0);
    auto xor_out = exp ^ key;

    std::bitset<32> s_box = s_function(xor_out);
    std::bitset<32> perm = permutation_function(s_box);
    
    std::bitset<32> r1 = perm ^ l0;

    std::cout << "r0: " << r0 << std::endl;
    std::cout << "l0: " << l0 << std::endl;
    std::cout << "key: " << key << std::endl;

    std::cout << "E(R0): " << exp << std::endl;
    std::cout << "XOR: " << xor_out << std::endl;
    std::cout << "S-Box: " << s_box << std::endl;
    std::cout << "P Box: " << perm << std::endl;

    std::cout << "R1: " << r1 << std::endl;

    return 0;
}
