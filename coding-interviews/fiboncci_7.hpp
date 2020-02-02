// [斐波那契数列](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3)
#pragma once
#include <cstdint>
#include <array>

namespace task7 {
    using namespace std;

    template<int N> //模板
    class Fibonacci
    {
    public:
        enum{Result = Fibonacci<N-1>::Result + Fibonacci<N-2>::Result };
    };

    template<>
    class Fibonacci<1>
    {
    public:
        enum { Result = 1 };
    };

    template<>
    class Fibonacci<0>
    {
    public:
        enum { Result = 0 };
    };

    template<int N>
    constexpr int fib() {
        return Fibonacci<N>::Result;
    }

    constexpr array<int,40> fibs = {fib<0>(),fib<1>(),fib<2>(),fib<3>(),fib<4>(),fib<5>(),fib<6>(),fib<7>(),fib<8>(),fib<9>(),
                                    fib<10>(),fib<11>(),fib<12>(),fib<13>(),fib<14>(),fib<15>(),fib<16>(),fib<17>(),fib<18>(),fib<19>(),
                                    fib<20>(),fib<21>(),fib<22>(),fib<23>(),fib<24>(),fib<25>(),fib<26>(),fib<27>(),fib<28>(),fib<29>(),
                                    fib<30>(),fib<31>(),fib<32>(),fib<33>(),fib<34>(),fib<35>(),fib<36>(),fib<37>(),fib<38>(),fib<39>()};

    class Solution {
    public:
        int Fibonacci(int n) {
            return fibs[n];
        }
    };
}