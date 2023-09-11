#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // write your code

  vector<vector<int> > breakInSizeOfN(vector<int>& arr, int N) {
    int groups = int(arr.size()) / N;
    int ind = 0;
    vector<vector<int> > result;
    for(int i = 0; i < groups; i++) {
      vector<int> v;
      for(int j = ind; j < ind + N; j++) {
        v.push_back(arr[j]);
      }
      ind = ind + N;
      result.push_back(v);
    }
    return result;
  }

  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int> > umap;
    for (int i = 0; i < groupSizes.size(); i++) {
      if (umap.find(groupSizes[i]) == umap.end()) {
        umap[groupSizes[i]] = {i};
      } else {
        umap[groupSizes[i]].push_back(i);
      }
    }

    vector<vector<int> > ans;
    for (auto it = umap.begin(); it != umap.end(); it++) {
      vector<vector<int> > temp = breakInSizeOfN(it->second, it->first);
      // cout << temp.size() << endl;
      for(auto el: temp) {
        ans.push_back(el);
      }
      // ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
  }

  void run() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    auto ans = groupThePeople(v);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
      for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << ",";
      }
      cout << endl;
    }
  }
};

int main() {
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  Solution *s = new Solution();
  s->run();
  return 0;
}