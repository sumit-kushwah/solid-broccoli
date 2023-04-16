#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
  int vi = 0, vj = 0, i = 0, j = 0;
  while(vi < word1.size() && 
        vj < word2.size() && 
        word1[vi][i] == word2[vj][j]
  ) {
    i++;
    j++;
    if (i == word1[vi].size()) {
      vi++;
      i = 0;
    }
    if (j == word2[vj].size()) {
      vj++;
      j = 0;
    }
  }
  if (vi < word1.size() || vj < word2.size()) return false;
  return true;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  cout << arrayStringsAreEqual({"a", "bc"}, {"ab", "c"});
  
  return 0;
}
