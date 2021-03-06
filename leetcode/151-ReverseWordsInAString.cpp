#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


// Solution 1 : sstream, O(n) place
class Solution {
public:
    string reverseWords(string s) {
        istringstream in(s);
        string w;
        string res;
        while (in >> w) res = (res.empty() ? w : w + " ") + res;
        return res;
    }
};


// Solution 2 : swap, O(1) place
class Solution_2 {
public:
    string reverseWords(string s) {
        auto si = s.find_first_not_of(' ');
        s.erase(0, si);
        auto sj = s.find_last_not_of(' ');
        s.erase(sj+1);
        reverse(s.begin(), s.end());

        int i = 0;
        int n = s.size();
        while (i < n) {
            int j = i;
            while (j < n && s[j] != ' ') ++j;
            reverse(s.begin()+i, s.begin()+j);
            ++j;
            int k = j;
            while (k < n && s[k] == ' ') ++k;
            if (k != j) {
                s.erase(j, k-j);
                n -= k-j;
            }
            i = j;
        }
        return s;
    }
};


int main() {
    Solution_2 s;
    string a = "    hello        world kiss     ";
    s.reverseWords(a);
    cout << a << endl;
    return 0;
}

