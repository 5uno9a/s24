#include "sparrow.h"
#include <iostream>
#include <bitset>

namespace sparrow {
    namespace warmup {
        unsigned CountBits(std::bitset<32> bits, unsigned pos, unsigned len){
            unsigned count = 0;
            // Making sure that the iterator stays inside the bounds of the bitset
            if (pos + len > 32) len = 32 - pos;

            for(unsigned i = pos; i < pos + len; ++i){
                // Treating the the value of the index as a boolean 
                if(bits.test(i)){
                    count++;
                }
            }

            return count;
        }

        unsigned CountBits(const std::vector<std::bitset<32>>& bitsets){
            unsigned count = 0;
            for(const auto& bits: bitsets){
                 count += bits.count(); 
             }
            return count;
        }


        std::pair<std::vector<std::bitset<32>>, bool> BitAnd(std::vector<std::bitset<32>> a,
                                                             std::vector<std::bitset<32>> b){

            std::vector<std::bitset<32>> result;
            bool isValid = a.size() == b.size();
            
            if(isValid){
                for(size_t i = 0; i < a.size(); ++i){
                    result.push_back(a[i] & b[i]); 
                }
            }

            return std::make_pair(result, isValid);
         }
         
    }
}