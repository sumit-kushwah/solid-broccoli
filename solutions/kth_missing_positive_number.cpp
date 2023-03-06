#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here
int findKthPositive(vector<int>& arr, int k) {
  int l = 0, r = arr.size() - 1, index = 0;
    while(l <= r) {
      int m = (l + r) / 2;
      int missing = arr[m] - (m + 1);
      // cout << missing << " " << l << " " << r << endl; 
      if (missing >= k) r = m - 1;
      else if (missing < k) {
          index = m;
          l = m + 1;
      }  
    }
    if (r == -1) return k;
    return arr[index] + (k - (arr[index] - (index + 1)));
  }  
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  
  return 0;
}