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
  DisjointSet(int n) {
    v = vector<int>(n);
    for (int i = 0; i < n; i++) v[i] = i;
  }

  void connect(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);
    v[root_a] = root_b;
  }

  bool isConnected(int a, int b) {
    return root(a) == root(b);
  }
};

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
  DisjointSet* ds = new DisjointSet(n);
  for (vector<int> v: edges) {
    ds->connect(v[0], v[1]);
  }
  return ds->isConnected(source, destination);
}

int main() {
  return 0;
}