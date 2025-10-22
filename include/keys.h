#ifndef KEYS_H
#define KEYS_H

#include <bitset>
#include <array>

std::bitset<56> join_function(const std::array<std::bitset<28>, 2>&);

std::bitset<28> shift_function(const std::bitset<28>&);

#endif
