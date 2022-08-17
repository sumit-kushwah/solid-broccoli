#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  string nextForm(string cur) {
    string ans = "";
    int count = 1;
    char curChar = cur[0];
    for (int i = 1; i < cur.size(); i++) {
      if (cur[i] == cur[i - 1]) {
        count++;
      } else {
        ans += to_string(count);
        ans.push_back(curChar);
        curChar = cur[i];
        count = 1;
      }
    }
    ans += to_string(count);
    ans.push_back(curChar);
    return ans;
  }
  string countAndSay(int n) {
    string base = "1";
    if (n == 1) return base;
    while(--n) {
      base = nextForm(base);
    }
    return base;
  }
  void run()
  {
    auto ans = this->countAndSay(4);
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