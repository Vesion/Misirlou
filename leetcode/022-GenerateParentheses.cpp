#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : Catalan recursive
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            for (string& s1 : generateParenthesis(i))
                for (string& s2 : generateParenthesis(n-i-1))
                    res.push_back(s1 + '(' + s2 + ')');
        }
        return res;
    }
};


// Solution 2 : Catalan iterative
class Solution_2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        dp.push_back({""});
        for (int i = 1; i <= n; ++i) {
            vector<string> r;
            for (int j = 0; j < i; ++j) {
                for (string& left : dp[j]) {
                    for (string& right : dp[i-1-j]) {
                        r.push_back("(" + left + ")" + right);
                    }
                }
            }
            dp.push_back(r);
        }
        return dp.back();
    }
};


// Solution 3 : generate one by one
class Solution_3 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, 0, "", res);
        return res;
    }

    // need left '('s and right ')'s
    void dfs(int left, int right, string path, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        if (left) dfs(left-1, right+1, path+"(", res); // a '(' must match a ')'
        if (right) dfs(left, right-1, path+")", res); // match
    }
};


int main() {
    return 0;
}
