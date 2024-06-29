#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // Approach1: Result TLE 
  void explore_ancestor(int explore_index, vector<bool>&explored, vector<set<int>>& ancestors) {
    for(int e1 : ancestors[explore_index]) {
      explored[e1] = true;
      explore_ancestor(e1, explored, ancestors);
      for(int e2 : ancestors[e1]) {
        ancestors[explore_index].insert(e2);
      }
    }
  }
  vector<vector<int>> getAncestors1(int n, vector<vector<int>>& edges) {
    vector<set<int> > ancenstors(n, set<int>());
    for(vector<int> v: edges) {
      int from = v[0];
      int to = v[1];
      ancenstors[to].insert(from);
    }
    vector<bool> ancenstors_explored(n, false);
    for(int i = 0; i < n; i++) {
      if (!ancenstors_explored[i]) {
        ancenstors_explored[i] = true;
        explore_ancestor(i, ancenstors_explored, ancenstors);
      }
    }
    vector<vector<int> > ans(n, vector<int>());
    for(int i = 0; i < n; i++) {
      for(int e: ancenstors[i]) {
        ans[i].push_back(e);
      }
    }
    return ans;
  }

  // Approach 2: Using BFS, Result: TLE
  void dfs(int index, vector<set<int>>& ans, vector<vector<int>>& graph) {
    queue<int> q;
    q.push(index);
    while(!q.empty()) {
      int ind = q.front();
      q.pop();
      for(int i = 0; i < graph[ind].size(); i++) {
        for(int e: ans[ind]) {
          ans[graph[ind][i]].insert(e);
        }
        ans[graph[ind][i]].insert(ind);
        q.push(graph[ind][i]);
      }
    }
  }
  vector<vector<int>> getAncestors2(int n, vector<vector<int>>& edges) {
    vector<vector<int> > graph(n, vector<int>());
    vector<set<int> > ans(n, set<int>());
    vector<bool> check_ancestor(n, false);
    for(int i = 0; i < edges.size(); i++) {
      graph[edges[i][0]].push_back(edges[i][1]);
      check_ancestor[edges[i][1]] = true;
    }
    for(int i = 0; i < n; i++) {
      if (!check_ancestor[i]) {
        dfs(i, ans, graph);
      }
    }

    vector<vector<int> > ancestors(n, vector<int>());
    for(int i = 0; i < n; i++) {
      for(int e: ans[i]) {
        ancestors[i].push_back(e);
      }
    }
    return ancestors;
  }

  // Approach 3: Using BFS but pushing only one element at a time
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int> > graph(n, vector<int>());
    vector<vector<int> > ans(n, vector<int>());
    for(int i = 0; i < edges.size(); i++) {
      graph[edges[i][0]].push_back(edges[i][1]);
    }
    for(int i = 0; i < n; i++) {
      stack<int> st;
      vector<bool> explored(n, false);
      st.push(i);
      while(!st.empty()) {
        int t = st.top();
        st.pop();
        for(int e: graph[t]) {
          if (!explored[e]) {
            ans[e].push_back(i);
            st.push(e);
            explored[e] = true;
          }
        }
        explored[t] = true;
      }
    }
    return ans;
  }

  void run() {
    
  }
};

int main() {
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  Solution *s = new Solution();
  s->run();
  return 0;
}