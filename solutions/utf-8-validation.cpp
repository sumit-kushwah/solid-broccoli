#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here

  int findType(int num) {
    if (num <= 127) return 1;
    if (num <= 191 && num >= 128) return 2;
    return 3;
  }
  int findN(int num) {
    if (num <= 127) return 0;
    if (num >= 192 && num <= 223) return 2;
    if (num >= 224 && num <= 239) return 3;
    if (num >= 240 && num <= 247) return 4;
    return -1;
  }
  bool validUtf8(vector<int>& data) {
    int count = 0;
    for (int e: data) {
      if (count > 0) {
        if (findType(e) != 2) return false;
        count--;
        continue;
      }
      if (findN(e) == -1) return false;
      count = findN(e) - 1;
    }
    if (count > 0) return false;
    return true;
  }

  void run()
  {
    vector<int> v = {3, 4, 5};
    auto ans = this->validUtf8(v);
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