#include <iostream>
#include <bitset>
#include <array>
#include <cstddef>

/* User Headers */

#include "encryption.h"
#include "ip.h"
#include "keys.h"
#include "pc.h"
#include "output.h"

int main(){
    /* bits{0b0100010001000101010100110110100101110011010001100101010101001110} */
    std::string plaintext = "DESisFUN";
    std::bitset<64> key{0b0000000100100011010001010110011110001001101010111100110111101111};

    try{
        auto plaintext_to_bits = string_to_bitset(plaintext);
	auto round_keys = key_schedule(key);
	auto enc = encryption_round(plaintext_to_bits, round_keys);

	std::cout << "Ciphertext: " << bitset_to_hex(enc) << std::endl;

    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
	return 1;
    }

    return 0;
}
