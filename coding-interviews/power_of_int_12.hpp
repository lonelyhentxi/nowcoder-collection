// [数值的整数次方](https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00)

#include <cstdint>
#define let const auto

namespace task12 {
    using namespace std;
    class Solution {
    public:
        double Power(double base, int exponent) {
            int64_t exp = exponent;
            if(exp<0) {
                base = 1.0/base;
                exp = -exp;
            }
            double prod = base;
            double factor = 1;
            while(exp) {
                if(exp & 1) {
                    factor *= prod;
                }
                prod *= prod;
                exp/=2;
            }
            return factor;
        }
    };
}