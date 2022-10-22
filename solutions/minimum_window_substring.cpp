#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here
string minWindow(string s, string t) {
  vector<int> upper_count(26), lower_count(26);
  vector<queue<int>> upper_queue(26), lower_queue(26);
  for (char ch: t) {
    if (ch >= 'a' && ch <= 'z') {
      int index = ch - 'a';
      lower_count[index]++;
    }
    if (ch >= 'A' && ch <= 'Z') {
      int index = ch - 'A';
      upper_count[index]++;
    }
  }

  int ans_length = INT_MAX;
  int ans_left = INT_MAX;
  int ans_right = 0;

  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (ch >= 'a' && ch <= 'z') {
      int index = ch - 'a';
      if (lower_count[index] > 0) {
        if (lower_count[index] == lower_queue[index].size()) {
          lower_queue[index].pop();
        }
        lower_queue[index].push(i);
      }
    }
    if (ch >= 'A' && ch <= 'Z') {
      int index = ch - 'A';
      if (upper_count[index] > 0) {
        if (upper_count[index] == upper_queue[index].size()) {
          upper_queue[index].pop();
        }
        upper_queue[index].push(i);
      }
    }

    bool success = true;
    for (int i = 0; i < 26; i++) {
      if (lower_count[i] != lower_queue[i].size()) success = false;
      if (upper_count[i] != upper_queue[i].size()) success = false;
    }
    if (success) {
      int left = INT_MAX, right = 0;
      for (int i = 0; i < 26; i++) {
        if (lower_count[i] > 0) {
          right = max(right, lower_queue[i].back());
          left = min(left, lower_queue[i].front());
        } 
        if (upper_count[i] > 0) {
          left = min(left, upper_queue[i].front());
          right = max(right, upper_queue[i].back());
        }
      }

      int cur_length = right - left + 1;
      if (cur_length < ans_length) {
        ans_length = cur_length;
        ans_left = left;
        ans_right = right;
      }
    }
  }

  string ans = "";
  // cout << ans_left << " " << ans_right << endl;
  while (ans_left <= ans_right) {
    ans.push_back(s[ans_left]);
    ans_left++;
  }

  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  string s, t;
  cin >> s >> t;
  cout << minWindow(s, t) << endl;
  
  return 0;
}