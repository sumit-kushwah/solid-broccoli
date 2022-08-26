#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  bool reorderedPowerOf2(int n) {
    string n_string = to_string(n);
    sort(n_string.begin(), n_string.end());
    for (int i = 1; i <= 1e9; i*=2) {
      string temp = to_string(i);
      sort(temp.begin(), temp.end());
      if (temp == n_string) {
        return true;
      }
    }
    return false;
  }
  void run()
  {
    auto ans = this->reorderedPowerOf2(46);
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