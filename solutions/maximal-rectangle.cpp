#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
   public:
    // write your code
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea = 0;
        vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    // look for up
                    v[i][j] = 1;
                    if ((i - 1) >= 0 && matrix[i - 1][j] == '1') {
                        v[i][j] = 1 + v[i - 1][j];
                    }
                }
            }

            for (int j = 0; j < matrix[i].size(); j++) {
                int minh = v[i][j];
                for (int k = j; k < matrix[i].size(); k++) {
                    minh = min(minh, v[i][k]);
                    maxarea = max(maxarea, (k - j + 1) * minh);
                }
            }
        }
        return maxarea;
    }
    void run() {
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution* s = new Solution();
    s->run();
    return 0;
}