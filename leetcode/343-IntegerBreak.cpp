#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dp, O(n^2)
class Solution {
public:
    int integerBreak(int n) {
        if (n == 1 || n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n+1, 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 3; // think about why we need to init dp[1..3] first?
        for (int i = 4; i <= n; ++i) {
            for (int j = i-1; j >= 1; --j) {
                dp[i] = max(dp[i], dp[i-j]*j);
            }
        }
        return dp[n];
    }
};


// Solution 2 : math, O(n) (or O(logn) if use fast power)
// https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem
class Solution_2 {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
};


int main() {
    Solution s;
    cout << s.integerBreak(10) <<endl;
    return 0;
}

