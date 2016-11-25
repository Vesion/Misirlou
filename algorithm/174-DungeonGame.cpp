#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()) return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX)); // dp[i][j] means the minimal health when we reach dungeon[i][j]
        dp[m-1][n] = dp[m][n-1] = 1;
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                int health = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = health > 0 ? health : 1;
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> d = {
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };
    cout << s.calculateMinimumHP(d) << endl;
    return 0;
}

