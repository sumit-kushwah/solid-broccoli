#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue <int> pq;
    int maxgo = startFuel;
    int ans = 0;
    for (auto v: stations) {
      while(v[0] > maxgo) {
        if (pq.empty()) return -1;
        maxgo += pq.top();
        pq.pop();
        ans++;
      }
      pq.push(v[1]);
    }
    while(target > maxgo) {
        if (pq.empty()) return -1;
        maxgo += pq.top();
        pq.pop();
        ans++;
    } 
    return ans;
  }
  void run()
  {
    vector<vector<int> > v = {{13,21},{26,115},{100,47},{225,99},{299,141},{444,198},{608,190},{636,157},{647,255},{841,123}};
    auto ans = this->minRefuelStops(1000, 299, v);
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