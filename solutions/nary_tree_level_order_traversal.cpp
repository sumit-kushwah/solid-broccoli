#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
  // write your function code here
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> q;
    if (root == nullptr) return {};
    q.push(root);
    vector<int> cur;
    queue<Node*> other;
    while(!q.empty()) {
      Node* f = q.front();
      cur.push_back(f->val);
      q.pop();
      for (Node* n: f->children) {
        other.push(n);
      }
      if (q.empty()) {
        q = other;
        ans.push_back(cur);
        cur.clear();
        other = queue<Node*>();
      } 
    }
    return ans;
  }
  void run()
  {
    // auto ans = this->function();
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