#include <bitset>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstddef>
#include <stdexcept>

std::string bitset_to_hex(const std::bitset<64>& ciphertext){
    std::stringstream output;
    output << std::hex << std::uppercase << std::setfill('0') << std::setw(16);
    output << ciphertext.to_ullong();

    return output.str();
}

std::bitset<64> string_to_bitset(std::string plaintext){
    if(plaintext.empty()){ throw std::invalid_argument("Plaintext cannot be empty."); }
    
    /* Will change to > 64 blocks later */

    if(plaintext.length() > 8){ throw std::invalid_argument("Plaintext cannot be over 64 bits."); }
    
    if(plaintext.length() < 8){
        plaintext.resize(8, '\0');
    }
    
    unsigned long long value = 0;
    for(size_t i = 0; i < 8; i++){
        value = (value << 8) | static_cast<unsigned char>(plaintext[i]);
    }

    return std::bitset<64>(value);
}
