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

    void DropZero(NullableInts* nullableInts){
        if(!nullableInts) return;

        for(size_t i = 0; i < nullableInts->nums.size(); ++i){
            if(nullableInts->nums[i]== 0){
                size_t bitsetIndex = i/32;
                size_t bitIndex = i % 32;

                if(bitsetIndex >= nullableInts->valid.size()){
                    nullableInts->valid.resize(bitsetIndex + 1);
                }

                nullableInts->valid[bitsetIndex].set(bitIndex, false);
            }
        }
    }

    AverageResult Average (const NullableInts* nullableInts){
        if(nullableInts == nullptr){
            return {0.0f, false};
        }

        float sum = 0.0f;
        size_t count = 0;

        for(size_t i = 0; i < nullableInts->nums.size(); ++i){
            if(i/32 < nullableInts->valid.size() && nullableInts-> valid[i/32].test(i%32)){
                sum += nullableInts->nums[i];
                ++count;
            }
        }
        
        if(count == 0){
            return {0.0f, false};
        }else {
            return {sum / count, true};
        }
    }

    DivideResult Divide (const NullableInts* numA, const NullableInts* numB){
        // Return for null inputs or size mismatch.
        if(numA == nullptr || numB == nullptr || numA->nums.size() != numB->nums.size()){
            return {{}, false};
        }

        auto [bitwiseAndResult, isValid] = warmup::BitAnd(numA->valid, numB->valid);

        if(!isValid){
            return {{}, false};
        }

        NullableInts result;
        result.nums.resize(numA->nums.size());
        result.valid = bitwiseAndResult;

        for(size_t i = 0; i < numA->nums.size(); ++i){
            if(bitwiseAndResult.size() > i / 32 && bitwiseAndResult[i/32].test(i%32)){
                if(numB->nums[i] != 0){
                    result.nums[i] = numA->nums[i] / numB-> nums[i];
                }else{
                    // Invalidate division by zero
                    result.valid[i/32].set(i % 32, false);
                }
            }
        }
        return {result, true};
    }

}