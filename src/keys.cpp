#include <iostream>

#include <bitset>
#include <array>
#include <cstddef>

/* Project headers */
#include "pc.h"

const int round_shift[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

/* joins two 28 bitsets -> 56 */
std::bitset<56> join_function(const std::array<std::bitset<28>, 2>& pc2_out){

    std::bitset<56> join;

    join |= (std::bitset<56>(pc2_out[0].to_ulong()) << 28);
    join |= std::bitset<56>(pc2_out[1].to_ulong());

    return join;

}

std::bitset<28> shift_function(const std::bitset<28>& part, int round){
    std::bitset<28> shift_out;

    //shift << round_shift[n] |= shift << 27 - round_shift[n]

    shift_out |= part << round_shift[round];
    shift_out |= part >> 28-round_shift[round];
    
    return shift_out;
}

std::array<std::bitset<48>, 16> key_schedule(const std::bitset<64>& original_key){

    /* Function creates all round keys k1 -> k16 */

    auto [c, d] = pc1_function(original_key);

    std::array<std::bitset<48>, 16> key_output;

    for(size_t i=0; i<16; i++){
        c = shift_function(c, i);
	d = shift_function(d, i);
        
	auto join_shifts = join_function({c, d});

	key_output[i] = pc2_function(join_shifts);
    }
    
    /* Debug | Verbose */
    std::cout << "-------------------------Key Generation----------------------" << std::endl;
    for(size_t i=0; i<16; i++){ std::cout << key_output[i] << std::endl; }
    std::cout << "\n\n" << std::endl;

    return key_output;
}
