#include <iostream>
#include <cstddef>

/* user headers */
#include "keys.h"
#include "pc.h"

int main(){
    
    std::bitset<64> key{0b0000000100100011010001010110011110001001101010111100110111101111};

    auto keys = key_schedule(key);

    for(size_t i=0; i<16; i++){
        std::cout << "K" << i << ": " << keys[i] << std::endl;
    }

    return 0;
}
