#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : sort, O(nlogn+n) time, O(1) space
class Solution_1 {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        // find the first one citations[i] < i+1
        // if use binary search here, we can get O(nlogn + logn) time
        for (int i = 0; i < n; ++i) {
            if (citations[i] < i+1) return i;
        }
        return n;
    }
};


// Solution 2 : counting sort, O(n) time, O(n) space
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int n = citations.size();
        vector<int> count(n+1, 0);
        for (int c : citations) {
            if (c > n) count[n]++;
            else count[c]++;
        }

        int total = 0;
        for (int i = n; i >= 0; --i) {
            total += count[i];
            if (total >= i) return i;
        }
        return 0;
    }
};



int main() {
    Solution s;
    vector<int> c = {6,5,3,3,1,0};
    cout << s.hIndex(c) << endl;
    return 0;
}

