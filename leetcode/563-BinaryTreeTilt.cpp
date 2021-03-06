#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }
    
    int postorder(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = postorder(root->left, res);
        int right = postorder(root->right, res);
        res += abs(left-right);
        return left+right+root->val;
    }
};


int main() {
    return 0;
}
