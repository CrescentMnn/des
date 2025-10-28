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

std::bitset<64> sequence_enc(const std::bitset<64>& key, std::string plaintext){
    auto plaintext_to_bits = string_to_bitset(plaintext);
    auto round_keys = key_schedule(key);
    auto enc = encryption_round(plaintext_to_bits, round_keys);

    return enc;
}

std::bitset<64> sequence_dec(const std::bitset<64>& key, const std::bitset<64>& ciphertext){
    auto round_keys = key_schedule(key);
    auto dec = decryption_round(ciphertext, round_keys);

    return dec;
}

int main(){
    /* bits{0b0100010001000101010100110110100101110011010001100101010101001110} */
    std::string plaintext = "DESisFUN";
    std::bitset<64> key{0b0000000100100011010001010110011110001001101010111100110111101111};

    try{

        auto encryption = sequence_enc(key, plaintext);
    	auto decryption = sequence_dec(key, encryption);

        std::cout << "Cipertext: " << encryption << "\n\nDecryption: " << decryption << std::endl;
        
        std::cout << "Hex: " << bitset_to_hex(string_to_bitset(plaintext)) << "\nHex dec: " << bitset_to_hex(decryption) << std::endl;

	if(decryption == string_to_bitset(plaintext)){ std::cout << "Decryption Correct" << std::endl; }
	else{ std::cout << "Verification failed" << std::endl; } 

    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
	return 1;
    }

    return 0;
}
