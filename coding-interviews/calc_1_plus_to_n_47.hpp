// [求1+2+3+...+n](https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1)
#pragma once
#include <functional>
namespace task47 {
    using namespace std;
    void sif(bool cond, function<bool()> expr1, function<bool()> expr2) {
        bool useless = ( ( cond && ( expr1() || true)) || expr2());
    }

    int mult(int m, int n, int sum) {
        bool useless;
        useless = ( n & 1 ) && ( sum += m);
        useless = ( n = (n >> 1) ) && ( m = (m << 1) ) ;
        sif( n==0 , [=]() { return true; }, [=, &sum]() {
            sum = mult(m, n, sum);
            return true;
        });
        return sum;
    }

    class Solution {
    public:
        int Sum_Solution(int n) {
            return  ( mult(n+1, n, 0) >> 1);
        }

    };
}
