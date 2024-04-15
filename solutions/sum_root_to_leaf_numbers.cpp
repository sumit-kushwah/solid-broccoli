#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    // write your code
    void helper(TreeNode *root, int *sum, int curval) {
        curval = curval * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            *sum += curval;
        }
        if (root->left != nullptr) {
            helper(root->left, sum, curval);
        }
        if (root->right != nullptr) {
            helper(root->right, sum, curval);
        }
    }

    int sumNumbers(TreeNode *root) {
        if (root == nullptr) return 0;
        int sum = 0;
        helper(root, &sum, 0);
        return sum;
    }

    void run() {
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution *s = new Solution();
    s->run();
    return 0;
}