#include <iostream>
#include <vector>
using namespace std;

// classic DP problem
// dp[i] = max{dp[i-1] + nums[i], nums[i]}
int maxSubArray(vector<int>& nums) {
    int dp = nums[0];
    int result = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp = max(dp + nums[i], nums[i]);
        result = max(dp, result);
    }
    return result;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}