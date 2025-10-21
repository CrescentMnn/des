#ifndef PC_H
#define PC_H

#include <bitset>
#include <array>

std::array<std::bitset<28>, 2> pc1_function(const std::bitset<64>&);

std::bitset<48> pc2_function(const std::bitset<56>&);

#endif
