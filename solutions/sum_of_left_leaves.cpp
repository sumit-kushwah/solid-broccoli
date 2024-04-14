#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

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
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
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