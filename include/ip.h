#ifndef IP_H
#define IP_H

const int ip_table[64] = {

};

const int ipinv_table[64] = {

};

std::bitset<64> ip_function(const std::bitset<64>&);

std::bitset<64> ip_inv_function(const std::bitset<64>&);

#endif
