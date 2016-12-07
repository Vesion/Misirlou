#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class NumArray {
public:
    vector<long long> sums;
    NumArray(vector<int> &nums) {
        sums.resize(nums.size()+1);
        partial_sum(nums.begin(), nums.end(), sums.begin()+1);
    }

    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
};


int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}
