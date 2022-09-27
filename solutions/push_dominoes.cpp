#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string pushDominoes(string dominoes) {
  int n = dominoes.size();
  int i = 0;
  while(i < n) {
    if (dominoes[i] == 'R') {
      int start = i;
      i++;
      while(i < n && dominoes[i] == '.') {
        i++;
      }
      if (i < n && dominoes[i] == 'L') {
        int l = start + 1;
        int r = i - 1;
        while(l < r) {
          dominoes[l++] = 'R';
          dominoes[r--] = 'L'; 
        }
      }
    } else {
      i++;
    }
  }
  for (int i = 1; i < n; i++) {
    if (dominoes[i] == '.' && dominoes[i - 1] == 'R') {
      if (i + 1 < n && dominoes[i + 1] == 'L') {
        continue;
      }
      dominoes[i] = 'R';
    }
  }    
  for (int i = n - 2; i >= 0; i--) {
    if (dominoes[i] == '.' && dominoes[i + 1] == 'L') {
      if (i - 1 >= 0 && dominoes[i - 1] == 'R') {
        continue;
      }
      dominoes[i] = 'L';
    }
  }
  return dominoes;
}

int main() {
  return 0;
}