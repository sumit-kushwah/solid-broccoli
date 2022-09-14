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
  int ans = 0;
  void run(TreeNode* root, vector<int> cur) {
    cur[root->val] += 1;
    if (root->left == NULL && root->right == NULL) {
      int oddcount = 0;
      for (int e: cur) {
        if (e & 1) oddcount++;
      }
      if (oddcount <= 1) ans += 1;
    }
    if (root->left) run(root->left, cur);
    if (root->right) run(root->right, cur);
  }
  int pseudoPalindromicPaths (TreeNode* root) {
      vector<int> cur(10);
      run(root, cur);
      return ans;
  }
  void run()
  {
    // auto ans = this->pseudoPalindromicPaths();
    // this->printAnswer(ans);
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