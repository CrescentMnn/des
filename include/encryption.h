#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <bitset>
#include <array>

std::bitset<32> s_function(const std::bitset<48>&);

std::bitset<32> feistel_function(const std::bitset<32>&, const std::bitset<48>&);

std::bitset<64> encryption_round(const std::bitset<64>&, const std::array<std::bitset<48>, 16>&);

#endif
