#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here

  vector<int> sortedSquaresImproved(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    vector<int> ans(nums.size());
    int curindex = nums.size() - 1;
    while(left <= right) {
      if (left == right) {
        ans[curindex--] = (nums[left] * nums[left]);
        break;
      }
      if (abs(nums[left]) >= abs(nums[right])) {
        ans[curindex--] = (nums[left] * nums[left]);
        left++;
      } else {
        ans[curindex--] = (nums[right] * nums[right]);
        right--;
      }
    }
    return ans;
  }
  vector<int> sortedSquares(vector<int>& nums) {
    int right = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= 0) {
        right = i;
        break;
      }
    }
    int left = right - 1;
    vector<int> ans;
    while(left >= 0 && right < nums.size()) {
      if (abs(nums[left]) <= nums[right]) {
        ans.push_back(nums[left] * nums[left]);
        left--;
      } else {
        ans.push_back(nums[right] * nums[right]);
        right++;
      }
    }

    while(left >= 0) {
      ans.push_back(nums[left] * nums[left]);
      left--;
    }

    while(right < nums.size()) {
      ans.push_back(nums[right] * nums[right]);
      right++;
    }
    return ans;
  }
  void run()
  {
    vector<int> v = {-4,-1,0,3,10};
    auto ans = sortedSquaresImproved(v);
    printAnswer(ans);
  }

  void printAnswer(auto ans) {
    string type = typeid(ans).name();
    if (type == "St6vectorIiSaIiEE") {
      for(auto p = ans.begin(); p != ans.end(); p++) {
        cout << *p << " ";
      }
      cout << endl;
    } else {
      // cout << ans << endl;
    }
  }
};

int main()
{
  Solution *s = new Solution();
  s->run();
}