#include <bits/stdc++.h>
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
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        if (depth == 2) {
            TreeNode *newLeft = new TreeNode(val);
            TreeNode *newRight = new TreeNode(val);
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
            return root;
        }
        if (depth > 2) {
            if (root->left != nullptr) {
                root->left = addOneRow(root->left, val, depth - 1);
            }
            if (root->right != nullptr) {
                root->right = addOneRow(root->right, val, depth - 1);
            }
            return root;
        }
        return nullptr;
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