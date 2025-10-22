#include "pc.h"

#include <iostream>
#include <bitset>
#include <cstddef>

const int pc1_left[28] = {
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36
};

const int pc1_right[28] = {
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4
};

const int pc2_table[56] = {
	14, 17, 11, 24, 1, 5,
	3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8,
	16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32
};

std::array<std::bitset<28>, 2> pc1_function(const std::bitset<64>& key){
    std::bitset<28> c;
    std::bitset<28> d;

    for(size_t i=0; i<28; i++){
        c[27-i] = key[64-pc1_left[i]];
	d[27-i] = key[64-pc1_right[i]];
    }

    return {c, d};
}

std::bitset<48> pc2_function(const std::bitset<56>& input){
    std::bitset<48> pc2_out;

    for(size_t i=0; i<48; i++){
        pc2_out[47-i] = input[56 - pc2_table[i]]; 
    }

    return pc2_out;
}
