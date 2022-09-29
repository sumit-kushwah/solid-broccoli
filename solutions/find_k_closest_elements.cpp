#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  vector<int> diff;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    diff.push_back(abs(arr[i] - x));
  }
  int mini = 0;
  int minv = diff[0];
  for (int i = 1; i < n; i++) {
      if (diff[i] < minv) {
        minv = diff[i];
        mini = i;
      }
  }
  vector<int> ans;
  ans.push_back(arr[mini]);
  int left = mini - 1;
  int right = mini + 1;
  int length = 1;
  while(length < k) {
    length++;
    if (left >= 0 && right < n) {
      if (diff[left] <= diff[right]) {
        ans.push_back(arr[left]);
        left--;
      } else {
        ans.push_back(arr[right]);
        right++;
      }
      continue;
    }
    if (left >= 0) {
      ans.push_back(arr[left]);
      left--;
    }
    if (right < n) {
      ans.push_back(arr[right]);
      right++;
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int n, k, x;
  cin >> n >> k >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<int> res = findClosestElements(v, k, x);
  for (int e: res) cout << e << " ";
  cout << endl;
  return 0; 
}