#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  int optimalAnswer(vector<int> first, vector<int> second) {
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int sum = 0;
    for (int i = 0; i < first.size(); i++)
      sum += first[i] * second[i];
    
    cout << sum << endl;
    return sum;
  }

  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();
    int ans = 0;
    vector<int> cur;
    for (int i = 0; i < m; i++) cur.push_back(nums[i]);
    ans = max(ans, optimalAnswer(cur, multipliers));
    for (int i = 0; i < m; i++) {
      cur[m - i - 1] = nums[n - i - 1];
      ans = max(ans, optimalAnswer(cur, multipliers));
    }
    return ans;
  }
  void run()
  { 
    // auto ans = this->maximumScore();
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