#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int> umap;
  for (int i = 0; i < nums.size(); i++) {
    int e = nums[i];
    if (umap[e] && (i - umap[e]) <= k) return true;
    umap[e] = i;
  }
  return false;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  
  return 0;
}