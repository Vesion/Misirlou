#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Solution 1 : recursive
class Solution_1 {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && ( n == 1 || (n % 3 == 0 && isPowerOfThree(n/3)));
    }
};

// Solution 2 : iterative
class Solution_2 {
public:
    bool isPowerOfThree(int n) {
        if (n > 1)
            while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};


// Solution 3 : maximum integer of power 3
// NOTE : this works only when the base is prime. (cannot use this to check power of 2, 4, ...)
class Solution_3 {
public:
    bool isPowerOfThree(int n) {
        int maxPowOf3 = pow(3, int(log(INT_MAX) / log(3)));
        return n > 0 && maxPowOf3%n == 0;
    }
};


// Solution 4 : log10(n) / log10(3) return an int
// NOTE : we cannot use log (natural log), but log10 (common log), because n=243, just a coincidence.
class Solution_4 {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};


// Solution 5 : check table, all of possible : [1, 3, ..., 387420489, 1162261467]
class Solution_5 {
public:
    bool isPowerOfThree(int n) {
        vector<int> pow3;
        for (int i = 1; i > 0 && i < INT_MAX; i *= 3) pow3.push_back(i);
        return binary_search(pow3.begin(), pow3.end(), n);
    }
};


// Solution 6 : ternary
// similar to 231-PowerOfTwo, we convert n to a string of ternary representation, then use regex to check if it matches "10*"
// due to tedious implementation, here just give out pseudo code
//
//bool isPowerOfThree_ternary(int n) {
    //return Interger.toString(n, 3).matches("10*");
//}


int main() {
    return 0;
}
