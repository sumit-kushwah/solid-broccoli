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
 
class Solution
{
public:
  // write your function code here
  int count = 0;
  void run(TreeNode* node, int maxv) {
    if (node->val >= maxv) {
      count++;
      maxv = node->val;
    }
    if (node->right) {
      run(node->right, maxv);
    }
    if (node->left) {
      run(node->left, maxv);
    }
  }
  int goodNodes(TreeNode* root) {
    run(root, INT_MIN);
    return count;
  }

  void run()
  {
    TreeNode* t = new TreeNode(3);
    t->left = new TreeNode(1);
    t->right = new TreeNode(4);
    t->left->left = new TreeNode(3);
    t->right->left = new TreeNode(1);
    t->right->right = new TreeNode(5);
    auto ans = this->goodNodes(t);
    this->printAnswer(ans);
  }

  void printAnswer(auto ans) {
    string type = typeid(ans).name();
    if (type == "St6vectorIiSaIiEE") {
      // for(auto p = ans.begin(); p != ans.end(); p++) {
      //   cout << *p << " ";
      // }
      cout << endl;
    } else {
      cout << ans << endl;
    }
  }
};

int main()
{
  Solution *s = new Solution();
  s->run();
}