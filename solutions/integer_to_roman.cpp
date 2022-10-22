#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here

string intToRoman(int num) {
  map<int, string> m;
  for (int adder = 1; adder <= 1000; adder *= 10) {
    char ch;
    if (adder == 1) {
      ch = 'I';
    } else if (adder == 10) {
      ch = 'X';
    } else if (adder == 100) {
      ch = 'C';
    } else if (adder == 1000) {
      ch = 'M';
    }
    string cur = "";
    for (int start = 1; start < 4; start++) {
      cur.push_back(ch);
      m[start*adder] = cur;
    }
    if (adder == 1) {
      cur = 'V';
    } else if (adder == 10) {
      cur = 'L';
    } else if (adder == 100) {
      cur = 'D';
    }
    for(int start = 5; start < 9; start++) {
      m[start*adder] = cur;
      cur.push_back(ch);
    }
  }
  m[4] = "IV";
  m[9] = "IX";
  m[40] = "XL";
  m[90] = "XC";
  m[400] = "XD";
  m[900] = "CM";
  vector<string> v;
  int mul = 1;
  while(num) {
    int rem = num % 10;
    num = num / 10;
    v.push_back(m[rem * mul]);
    mul *= 10;
  }
  string ans = "";
  for(int i = v.size() - 1; i >= 0; i--) {
    ans += v[i];
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;cin >> t;
  while(t--) {
    int x; cin >> x;
    cout << intToRoman(x) << endl;
  }
  
  return 0;
}