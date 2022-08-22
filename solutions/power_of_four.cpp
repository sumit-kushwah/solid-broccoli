#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here

  bool isPowerOfFour1(int n) {
    return (((n & (n - 1) == 0)) && (n & 0x55555555));
  }

  bool isPowerOfFour(int n) {
      if (n <= 0) return false;
      while(n % 4 == 0) {
          n = n / 4;
      }
      return n == 1 ? true: false;
  }
  void run()
  {
    auto ans = this->isPowerOfFour(16);
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