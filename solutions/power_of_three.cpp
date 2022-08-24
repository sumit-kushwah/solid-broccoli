#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  bool isPowerOfFour1(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
  bool isPowerOfThree(int n) {
      if (n <= 0) return false;
      while(n % 3 == 0) {
          n = n / 3;
      }
      return n == 1 ? true: false;
  }
  void run()
  {
    auto ans = this->isPowerOfThree(27);
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