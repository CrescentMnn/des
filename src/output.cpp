#include <bitset>
#include <iomanip>
#include <sstream>

std::string bitset_to_hex(const std::bitset<64>& ciphertext){
    std::stringstream output;
    output << std::hex << std::uppercase << std::setfill('0') << std::setw(16);
    output << ciphertext.to_ullong();

    return output.str();
}
