#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class DisjointSet {
private:
  vector<int> v;
  int root(int i) {
    while(v[i] != i) {
      i = v[i];
    }
    return i;
  }
public:
  // creating disjoint set with n elements
  DisjointSet(int n) {
    v = vector<int>(n);
    // setting root itself for each element
    for (int i = 0; i < n; i++) v[i] = i;
  }

  // connecting two indices of vector
  void connect(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);
    v[root_a] = root_b;
  }

  // checking whether two indices are connected or not
  bool isConnected(int a, int b) {
    return root(a) == root(b);
  }
};

bool equationsPossible(vector<string>& equations) {
  DisjointSet* ds = new DisjointSet(26);
  for (string s: equations) {
    if (s[1] == '=') {
      ds->connect(s[0] - 'a', s[3] - 'a');
    }
  }
  for (string s: equations) {
    if (s[1] == '!') {
      if (ds->isConnected(s[0] - 'a', s[3] - 'a')) return false;
    }
  }
  return true;
}

int main() {
  return 0;
}