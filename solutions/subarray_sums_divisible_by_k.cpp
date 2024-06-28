#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // write your code
  int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remain(k, 0);
        int ans = 0;
        int sum = 0;
        remain[0]++;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int index = (sum % k + k) % k;
            remain[index]++;
        }
        // for(int i = 0; i < k; i++) {
        //     cout << remain[i] << " ";
        // }
        // cout << endl;
        for(int i = 0; i < k; i++) {
            ans += (remain[i] * (remain[i] - 1)) / 2;
        }
        return ans;
  }

  void run() {
    vector<int> nums;
    int k;

    // Read vector<int> nums
    int n;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Read int k
    cin >> k;
    cout << subarraysDivByK(nums, k);
  }
};

int main() {
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  Solution *s = new Solution();
  s->run();
  return 0;
}