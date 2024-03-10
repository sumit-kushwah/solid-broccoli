#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // write your code
  int minCostConnectPoints(vector<vector<int>>& points) {
    vector<bool> connected(points.size(), false);
    if (points.size() == 1) return 1;
    //sort(points.begin(), points.end());
    int totalCost = 0;
    for(int i = 0; i < points.size(); i++) {
      if (connected[i]) {
        //cout << "index;" << i << endl;
        continue;
      }
      int minj = 0;
      int minCost = INT_MAX;
      for(int j = 0; j < points.size(); j++) {
        if (i != j) {
          int tempCost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
          if (tempCost < minCost) {
            minCost = tempCost;
            minj = j;
          }
        }
      }
      connected[i] = true;
      connected[minj] = true;
      //cout << i << " " << minj << endl;
      //cout << minCost << endl;
      totalCost += minCost;
    }
    return totalCost;
  }

  void run() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << minCostConnectPoints(points) << endl;
  }
};

int main() {
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  Solution *s = new Solution();
  s->run();
  return 0;
}