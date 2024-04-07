#include "sparrow.h"
#include <iostream>
#include <bitset>
#include <vector>

 // print NullableInts                                                                    
std::ostream& operator<<(std::ostream &os, const sparrow::NullableInts &obj) {
    os << "NullableInts: [";
    for (size_t i = 0; i < obj.nums.size(); i++) {
        if (obj.valid[i / 32][i % 32]) {
            os << obj.nums[i];
        } else {
            os << "null";
        }
        if (i < obj.nums.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
   
    sparrow::NullableInts nints1{
        .nums={20,999,40,60},
        .valid=std::vector<std::bitset<32>>{std::bitset<32>{"00000000000000000000000000001101"}}
        };
    sparrow::NullableInts nints2{
        .nums={10,10,0,20}, 
        .valid= std::vector<std::bitset<32>>{std::bitset<32>{"00000000000000000000000000001111"}}
        };

    sparrow::DropZero(&nints2);

    auto nints12Division = sparrow::Divide(&nints1, &nints2);

    if(nints12Division.ok){
        auto nints12Average = sparrow::Average(&nints12Division.value);

        if(nints12Average.ok){
            std::cout << nints12Average.value << "\n";
        }else {
            std::cout << "Could not compute an average from the divison results." << "\n";

        }
    }else{
        std::cout << "Divsion operation was not successful." << "\n";
    }
    
    return 0;
}