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

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
  if (root1 == NULL && root2 == NULL) {
    return NULL;
  } else if (root1 == NULL) {
    return root2;
  } else if (root2 == NULL) {
    return root1;
  } else {
    root1->val = root1->val + root2->val;
    root1->right = mergeTrees(root1->right, root2->right);
    root1->left = mergeTrees(root1->left, root2->left);
    return root1;
  }
}
int main() {
  return 0;
}