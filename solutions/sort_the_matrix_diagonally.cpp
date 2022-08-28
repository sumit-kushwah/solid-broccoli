#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  void sortDiagonal(vector<vector<int>>& mat, int row, int col, int m, int n) {
    vector<int> count(101);
    int trow = row;
    int tcol = col;
    while(row < m && col < n) {
      count[mat[row][col]]++;
      row++;
      col++;
    }

    for (int i = 0; i < count.size(); i++) {
      while (count[i]--) {
        mat[trow][tcol] = i;
        trow++;
        tcol++;
      }
    }
  }
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++) {
      sortDiagonal(mat, i, 0, m, n);
    }
    for (int i = 1; i < n; i++) {
      sortDiagonal(mat, 0, i, m, n);
    }
    return mat;
  }
  
  void run()
  {
    vector<vector<int> > mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    auto ans = this->diagonalSort(mat);
    this->printAnswer(ans);
    cout << endl;
  }

  void printAnswer(auto ans) {
    for (auto v: ans) {
      for (auto e: v) {
        cout << e << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *s = new Solution();
  s->run();
}