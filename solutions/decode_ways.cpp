#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here

unordered_map<int, int> umap;

int run(string s, int i) {
  if (umap[i]) return umap[i];
  if (s.size() == i) return 1;
  if (s[i] == '0') return 0;
  int ans = 0;
  ans += run(s, i + 1);
    if (i + 1 < s.size() && s[i] == '1') {
      ans += run(s, i + 2);
  }
  if (i + 1 < s.size() && s[i] == '2' && s[i + 1] <= '6') {
      ans += run(s, i + 2);
  }
  umap[i] = ans;
  return ans;
}

int numDecodings(string s) {
    return run(s, 0);      
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  cout << numDecodings("226");
  return 0;
}