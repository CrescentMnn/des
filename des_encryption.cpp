#include <iostream>
#include <bitset>
#include <array>
#include <cstddef>

/* User Headers */

#include "encryption.h"
#include "ip.h"
#include "keys.h"
#include "pc.h"

int main(){

    std::bitset<64> key{0b0000000100100011010001010110011110001001101010111100110111101111};
    std::bitset<64> plt{0b0000000100100011010001010110011110001001101010111100110111101111};
    
    auto keys = key_schedule(key);
    auto ciphertext = encryption_round(plt, keys);
    for(size_t i=0; i<16; i++){
        std::cout << "K" << i << ": " << keys[i] << std::endl;
    }

    std::cout << "\n\n" << std::endl;

    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
}
