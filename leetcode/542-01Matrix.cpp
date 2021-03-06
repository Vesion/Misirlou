#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Solution 1 : multi-ends BFS, O(n)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        res.resize(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (mat[i][j]) res[i][j] = -1;
            else q.push({i, j});
        }
        int step = 1;
        constexpr int go[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i,j] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d], nj = j+go[d+1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (res[ni][nj] != -1) continue;
                    q.push({ni, nj});
                    res[ni][nj] = step;
                }
            }
            ++step;
        }
        return res;
    }
};


// Solution 2 : dp, O(n)
class Solution2 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (matrix[i][j] == 1) dp[i][j] = m+n;

        // traverse forward
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && dp[i][j] > dp[i-1][j]+1) dp[i][j] = dp[i-1][j]+1; // update with up
                if (j > 0 && dp[i][j] > dp[i][j-1]+1) dp[i][j] = dp[i][j-1]+1; // update with left
            }
        }
        // traverse backward
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (i < m-1 && dp[i][j] > dp[i+1][j]+1) dp[i][j] = dp[i+1][j]+1; // update with down
                if (j < n-1 && dp[i][j] > dp[i][j+1]+1) dp[i][j] = dp[i][j+1]+1; // update with right
            }
        }
        return dp;
    }
};


int main() {
    return 0;
}
