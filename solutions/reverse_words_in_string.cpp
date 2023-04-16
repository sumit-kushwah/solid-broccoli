#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here

string reverseWords(string s) {
  string cur = "";
  string ans = "";
  for(char ch: s) {
    if (ch == ' ') {
      if(cur.size() > 0) ans = cur + " " + ans;
      cur = " ";
      continue;
    }
    cur.push_back(ch);
  }
  if (cur.size() > 0) ans = cur + " " + ans;
  ans.pop_back();
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  
  return 0;
}