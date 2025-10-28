#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <bitset>
#include <array>

std::array<std::bitset<32>, 2> split_function(const std::bitset<64>&);

std::bitset<32> s_function(const std::bitset<48>&);

std::bitset<48> expansion_function(const std::bitset<32>&);

std::bitset<32> permutation_function(const std::bitset<32>&);

std::bitset<32> feistel_function(const std::bitset<32>&, const std::bitset<48>&);

std::bitset<64> encryption_round(const std::bitset<64>&, const std::array<std::bitset<48>, 16>&);

std::bitset<64> decryption_round(const std::bitset<64>&, const std::array<std::bitset<48>, 16>&);

#endif
