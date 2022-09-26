#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> umap(500, -1);
int run(int index, int k,int n, vector<int>& arr) {
  if (index >= n) return 0;
  if (umap[index] != -1) return umap[index];
  int sum = 0;
  int maxv = 0;
  for (int i = index; i < min(n, index + k); i++) {
    maxv = max(maxv, arr[i]);
    int maxmul = (i - index + 1) * maxv;
    int cursum = maxmul + run(i + 1, k, n, arr);
    sum = max(sum, cursum);
  }
  umap[index] = sum;
  return sum;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
  return run(0, k, arr.size(), arr);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << maxSumAfterPartitioning(arr, k);
  return 0;
}