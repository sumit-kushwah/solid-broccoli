#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here



int findRepititiveElement(vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    while(nums[i] != nums[nums[i] - 1]) swap (nums[i], nums[nums[i] - 1]);
    if (nums[i] != i + 1) return nums[i];
  }
  return 0;
}

vector<int> findErrorNumsMethod4(vector<int>& nums) {
  int rep = findRepititiveElement(nums);
  int x = 0;
  int i = 1;
  for (int e: nums) {
    x ^= e;
    x ^= i;
    i++;
  }
  return {rep , x ^ rep};
}

vector<int> findErrorNumsMethod3(vector<int>& nums) {
  int rep = findRepititiveElement(nums);
  long actual_sum = 0, natural_sum = 0;
  int n = nums.size();
  natural_sum = long((long)(n) * long(n + 1)) / (long)2;
  int lost = 0;
  for (int e: nums) actual_sum += long(e);
  if (actual_sum > natural_sum) {
    long cur_sum = 0, cur_natural_sum = long(long(rep) * long(rep - 1)) / 2;
    for (int e: nums)
      if (e < rep)
        cur_sum += e;
    lost = cur_natural_sum - cur_sum;
  } else {
    long cur_sum = 0, cur_natural_sum = natural_sum - (long(long(rep) * long(rep + 1)) / 2);
    for (int e: nums)
      if (e > rep)
        cur_sum += e;
    lost = cur_natural_sum - cur_sum;
  }
  return {rep, lost};
}

vector<int> findErrorNumsMethod2(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int lost = 0, rep;
  for (int i = 0; i < nums.size() - 1; i++) {
    int diff = nums[i + 1] - nums[i];
    if (diff == 2) lost = nums[i] + 1;
    if (diff == 0) rep = nums[i];
  }
  if (lost == 0) {
    if (nums[0] == 2) lost = 1;
    else lost = nums.size();
  }
  return {rep, lost};
}

vector<int> findErrorNums(vector<int>& nums) {
  sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        ans.push_back(nums[i]);
      }
    }
    vector<int> m(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i] - 1] = 1;
    }
    for(int i = 0; i < nums.size(); i++) {
      if (m[nums[i] - 1] == 0) {
        ans.push_back(i + 1);
      }
    }
    return ans;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  
  return 0;
}