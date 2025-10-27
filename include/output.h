#ifndef OUTPUT_H
#define OUTPUT_H

#include <bitset>
#include <string>

std::string bitset_to_hex(const std::bitset<64>&);

std::bitset<64> string_to_bitset(std::string plaintext);

#endif
