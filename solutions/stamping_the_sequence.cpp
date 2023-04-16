#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  vector<int> movesToStamp(string stamp, string target) {
    
  }
  void run()
  {
    auto ans = this->movesToStamp("abc", "ababc");
    this->printAnswer(ans);
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