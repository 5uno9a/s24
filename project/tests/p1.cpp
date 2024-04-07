#include "sparrow.h"
#include <iostream>
#include <bitset>

int main() {
   
    //testing the function BitAnd
    std::bitset<32> bits1{"11100000000001100000000000100010"};
    std::bitset<32> bits2{"01110000000001111000000000100001"};

    std::vector<std::bitset<32>> vector_1 = {bits1}; 
    std::vector<std::bitset<32>> vector_2 = {bits2}; 

    auto result_pair = sparrow::warmup::BitAnd(vector_1, vector_2);
    auto result_vector = result_pair.first;

    unsigned count_ones = 0;
    for(const auto& bits: result_vector){
        count_ones += sparrow::warmup::CountBits(bits, 0, 32);
    }

    std::cout << count_ones << std::endl; 
   
    return 0;
}