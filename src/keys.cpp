#include <iostream>

#include <bitset>
#include <array>
#include <cstddef>

const int round_shift[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

/* joins two 28 bitsets -> 56 */
std::bitset<56> join_function(const std::array<std::bitset<28>, 2>& pc2_out){

    std::bitset<56> join;

    join |= (std::bitset<56>(pc2_out[0].to_ulong()) << 28);
    join |= std::bitset<56>(pc2_out[1].to_ulong());

    return join;

}

std::bitset<28> shift_function(const std::bitset<28>& part){
    std::bitset<28> shift_out;

    //shift << round_shift[n] |= shift << 27 - round_shift[n]

    shift_out |= part << round_shift[n];
    shift_out |= part >> 28-round_shift[n];
    
    return shift_out;
}
