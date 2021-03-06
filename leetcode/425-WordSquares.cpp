#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* nexts[26];
        TrieNode() { isEnd = false; fill_n(nexts, 26, nullptr); }
    };
    TrieNode* root;
    
    void insert(string& w) {
        TrieNode* cur = root;
        for (char& c : w) {
            if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
        }
        cur->isEnd = true;
    }
    
    vector<string> search(string prefix) {
        vector<string> res;
        search(prefix, 0, root, "", res);
        return res;
    }
    
    void search(string& prefix, int start, TrieNode* cur, string path, vector<string>& res) {
        if (cur->isEnd) {
            res.push_back(path);
            return;
        }
        if (start < (int)prefix.size()) {
            char c = prefix[start];
            if (cur->nexts[c-'a']) search(prefix, start+1, cur->nexts[c-'a'], path+c, res);
        } else {
            for (char c = 'a'; c <= 'z'; ++c) 
                if (cur->nexts[c-'a']) search(prefix, start+1, cur->nexts[c-'a'], path+c, res);
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return {};
        root = new TrieNode();
        for (string& w : words) insert(w);

        int n = words[0].size();
        vector<vector<string>> res;
        for (string& w : words) {
            vector<string> path({w});
            dfs(1, n, path, res);
        }
        return res;
    }
    
    void dfs(int row, int n, vector<string>& path, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(path);
            return;
        }
        string prefix;
        for (string& w : path) prefix += w[row];
        auto words = search(prefix);
        for (string& w : words) {
            path.push_back(w);
            dfs(row+1, n, path, res);
            path.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<string> words = {"area","lead","wall","lady","ball"};
    auto r = s.wordSquares(words);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

