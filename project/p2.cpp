#include "sparrow.h"
#include <iostream>
#include <bitset>

int main() {
    // print NullableInts                                                                    
    td::ostream& operator<<(std::ostream &os, sparrow::NullableInts &obj) {
        std::cout << "NullableInts: [";
        for (int i=0; i<obj.nums.size(); i++) {
            if (obj.valid[i/32][i%32]) {
            std::cout << obj.nums[i];
            } else {
            std::cout << "null";
            }
            if (i < obj.nums.size()-1) {
            std::cout << ", ";
            }
        }
        std::cout << "]\n";
        return os;
    }

    



}