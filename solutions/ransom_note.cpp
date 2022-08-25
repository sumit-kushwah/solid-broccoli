#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> v(26);
    for (char ch: ransomNote) v[ch - 'a']++;
    for (char ch: magazine) v[ch - 'a']--;
    for (int rem: v) if (rem > 0) return false;
    return true;
  }
  void run()
  {
    auto ans = this->canConstruct("aa", "aab");
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