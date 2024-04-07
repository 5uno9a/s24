#include <bitset>
#include <vector>
#include <utility>

namespace sparrow {
    namespace warmup {

        unsigned CountBits(std::bitset<32> bits, unsigned pos, unsigned len);

        unsigned CountBits(const std::vector<std::bitset<32>>& bitsets);

        std::pair<std::vector<std::bitset<32>>, bool> BitAnd(std::vector<std::bitset<32>> a,
                                                     std::vector<std::bitset<32>> b);
    }

   struct NullableInts {
        std::vector<int> nums;
        std::vector<std::bitset<32>> valid;
    };

    void DropZero(NullableInts* nullableInts);
    
     struct AverageResult {
        float value;
        bool ok;
    };

    AverageResult Average(const NullableInts* nullableInts);

    struct DivideResult {
        NullableInts value;
        bool ok;
    };

    DivideResult Divide(const NullableInts* numA, const NullableInts* numB);

}


