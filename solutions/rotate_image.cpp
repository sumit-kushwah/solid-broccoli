#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here

  void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }

  void reversed(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      int start = 0;
      int end = n - 1;
      while(start < end) {
        swap(matrix[i][start], matrix[i][end]);
        start++;
        end--;
      }
    }
  }

  void rotate(vector<vector<int>>& matrix) {

    transpose(matrix);
    reversed(matrix);
    // int n = matrix.size();
    // for (int start = 0; start < n / 2; start++) {
    //   int col = start;
    //   int end = n - 1 - start;
    //   while(col < n - start - 1) {
    //     swap(matrix[start][col], matrix[col][n - 1 - start]);
    //     swap(matrix[start][col], matrix[n - 1 - start][end]);
    //     swap(matrix[start][col], matrix[end][start]);
    //     col++;
    //     end--;
    //   }
    // }
  }
  void run()
  {
    vector<vector<int>> v = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    this->rotate(v);
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++) {
        cout << v[i][j] <<  " ";
      }
      cout << endl;
    }
    // this->printAnswer(ans);
  }

  void printAnswer(auto ans) {
    string type = typeid(ans).name();
    if (type == "St6vectorIiSaIiEE") {
      // for(auto p = ans.begin(); p != ans.end(); p++) {
      //   cout << *p << " ";
      // }
      cout << endl;
    } else {
      cout << ans << endl;
    }
  }
};

int main()
{
  Solution *s = new Solution();
  s->run();
}