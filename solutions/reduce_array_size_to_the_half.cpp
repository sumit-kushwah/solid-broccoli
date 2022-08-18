#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  int minSetSize(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      int count = 1;
      vector<int> countArr;
      for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
          count++;
        } else {
          countArr.push_back(count);
          count = 1;
        }
      }
      countArr.push_back(count);
      sort(countArr.begin(), countArr.end(), greater<int>());
      int curlen = 0;
      int ans = 0;
      for(int freq: countArr) {
        curlen += freq;
        ans++;
        if (curlen >= (arr.size() / 2)) {
          break;
        }
      }
      return ans;
  }
  void run()
  {
    vector<int> v = {7,7,7,7,7,7};
    auto ans = this->minSetSize(v);
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