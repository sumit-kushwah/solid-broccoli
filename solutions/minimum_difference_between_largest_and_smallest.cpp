#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // write your code
  int minDifference(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      if (n <= 3) return 0;
      int ans = nums[n - 4] - nums[0];
      ans = min(ans, nums[n - 3] - nums[1]);
      ans = min(ans, nums[n - 2] - nums[2]);
      ans = min(ans, nums[n - 1] - nums[3]);
      return ans;
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