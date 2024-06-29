#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // write your code

  void run() {
    int n, len;
    cin >> n >> len;
  }
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> degree(n, 0);
    for(int i= 0; i < roads.size(); i++) {
      degree[roads[i][0]]++;
      degree[roads[i][1]]++;
    }
    sort(degree.begin(), degree.end(), greater<int>());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (long long)degree[i] * (long long)(n - i);
    }
    return ans;
  }
};

int main() {
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  Solution *s = new Solution();
  s->run();
  return 0;
}