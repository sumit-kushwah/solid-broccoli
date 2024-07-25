#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> buildGraph(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> graph(k + 1, vector<int>());
        for(int i = 0; i < conditions.size(); i++) {
            graph[conditions[i][0]].push_back(conditions[i][1]);
        }
        return graph;
    }
    
    // Kahn's algorithm for topological sorting
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        // calculate indegree
        vector<int> indegree(k + 1, 0);
        vector<vector<int>> graph = buildGraph(k, conditions);
        for(int i = 0; i < conditions.size(); i++) {
            indegree[conditions[i][1]]++;
        }
        queue<int> q;
        for(int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int f = q.front();
            ans.push_back(f);
            q.pop();
            for(int n: graph[f]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans;
        vector<int> rowSorted = topologicalSort(k, rowConditions);
        vector<int> colSorted = topologicalSort(k, colConditions);
        if (rowSorted.size() < k || colSorted.size() < k) {
            return ans;
        }
        ans = vector<vector<int>>(k, vector<int>(k, 0));
        for(int i = 0; i < rowSorted.size(); i++) {
            ans[i][0] = rowSorted[i];
        }

        for(int i = 0; i < colSorted.size(); i++) {
            for(int j = 0; j < rowSorted.size(); j++) {
                if (colSorted[i] == rowSorted[j]) {
                    ans[j][0] = 0;
                    ans[j][i] = colSorted[i];
                    rowSorted[j] = 0;
                }
            }
        }
        return ans;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution *s = new Solution();
    return 0;
}