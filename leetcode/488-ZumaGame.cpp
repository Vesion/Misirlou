#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> m;
        for (char& c : hand) m[c]++;
        int res = dfs(board, m);
        return res == INT_MAX ? -1 : res;
    }
    
    int dfs(string board, unordered_map<char,int>& m) {
        if (board.empty()) return 0;
        int res = INT_MAX;
        for (int i = 0; i < (int)board.size(); ++i) {
            if (i > 0 && board[i] == board[i-1]) continue; // avoid duplicate cases
            if (m[board[i]] == 0) continue;
            m[board[i]]--;
            string cb = board;
            cb.insert(i, string(1, board[i]));
            eliminate(cb);
            int t = dfs(cb, m);
            if (t < INT_MAX) res = min(res, t+1);
            m[board[i]]++;
        }
        return res;
    }
    
    void eliminate(string& s) {
        while (true) {
            bool f = false;
            int i = 0, n = s.size();
            string r;
            while (i < n) {
                int j = i+1;
                while (j < n && s[j] == s[j-1]) ++j;
                if (j-i >= 3) { i = j; f = true; }
                else r.push_back(s[i++]);
            }
            s = r;
            if (!f) break;
        }
    }
};


int main() {
    Solution s;
    cout << s.findMinStep("WRRBBW", "RB") << endl;
    cout << s.findMinStep("WWRRBBWW", "WRBRW") << endl;
    cout << s.findMinStep("G", "GGGGG") << endl;
    cout << s.findMinStep("RBYYBBRRB", "YRBGB") << endl;
    return 0;
}
