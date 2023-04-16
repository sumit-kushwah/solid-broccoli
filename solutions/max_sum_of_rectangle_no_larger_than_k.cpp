#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  // with time O(m^2n^2) is straight-forward and can be solved easily
  // solve with kadane algorithm and check correctness
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      int m = matrix.size();
      int n = matrix[0].size();
      for (int i = 0; i < m; i++) {
        vector<int> cur(n);
        for (int j = i; j < m; j++) {
          for (int k = 0; k < n; k++) {
            // cur[k] += 
          }
        }
      }
  }
  void run()
  {
    vector<vector<int>> mat = {{1, 0, 1}, {0, -2, 3}};
    auto ans = this->maxSumSubmatrix(mat, 2);
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