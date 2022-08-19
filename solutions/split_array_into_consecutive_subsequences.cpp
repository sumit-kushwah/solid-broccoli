#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here

  bool possibleInInterval(vector<int>&countArr, pair<int, int>& p) {
    int start = p.first;
    int end = p.second;
    int length = end - start + 1;
    if (length < 3) return false;
    int onecount = countArr[start];
    int twocount = 0;
    int othercount = 0;
    // cout << onecount << " " << twocount << " " << othercount << endl;
    for(int i = start + 1; i <= end; i++) {
      int reqcount = onecount + twocount;
      if (reqcount > countArr[i]) return false;
      int tempothercount = twocount;
      twocount = onecount;
      int remcount = countArr[i] - reqcount;

      if (othercount >= remcount) {
        othercount = remcount;
        onecount = 0;
      } else {
        onecount = remcount - othercount;
      }
      othercount += tempothercount;

      // cout << onecount << " " << twocount << " " << othercount << endl;
    }

    if ((onecount + twocount) > 0) return false;
    return true;
  }

  bool isPossible(vector<int>& nums) {
      vector<int> arr, countArr;
      int count = 1;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
          count++;
        } else {
          arr.push_back(nums[i - 1]);
          countArr.push_back(count);
          count = 1;
        }
      }
      arr.push_back(nums.back());
      countArr.push_back(count);
      
      vector<pair<int, int> > intervals;
      int cur = 0;
      for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1] + 1) {
          intervals.push_back({cur, i - 1});
          cur = i;
        }
      }
      intervals.push_back({cur, arr.size() - 1});

      for(pair<int, int> p: intervals) {
        if (!possibleInInterval(countArr, p)) return false;
      }

      return true;
  }
  void run()
  {
    vector<int> v = {1,2,3,4,4,5};
    auto ans = this->isPossible(v);
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