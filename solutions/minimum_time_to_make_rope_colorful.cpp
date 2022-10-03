#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here
int minCost(string colors, vector<int>& neededTime) {
  int maxcost = neededTime[0];
  int totalcost = neededTime[0];
  int finalcost = 0;
  for(int i = 1; i < colors.size(); i++) {
    if (colors[i] == colors[i - 1]) {
      maxcost = max(maxcost, neededTime[i]);
      totalcost += neededTime[i];
    } else {
      finalcost += totalcost - maxcost;
      maxcost = neededTime[i];
      totalcost = neededTime[i];
    }
  }
  finalcost += totalcost - maxcost;
  return finalcost;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  
  return 0;
}