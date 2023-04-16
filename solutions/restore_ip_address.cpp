#include<bits/stdc++.h>
using namespace std;

vector<string> restoreIpAddresses(string s) {
    int L = s.size();
    if (L < 4 || L > 12) return {};
    // 255678976
    vector<string> ans;
    for(int i = 0; i <= 2; i++) {
        for(int j = i + 1; j <= i + 3 && j < L - 3; j++) {
            for(int k = j + 1; k <= j + 3 && k < L - 2; k++) {
                for (int l = k + 1; l <= k + 3 && l < L - 3; l++) {
                    int first = stoi(s.substr(0, i + 1));
                    int second = stoi(s.substr(j, k - j));
                    int third = stoi(s.substr(k, l - k));
                    int four = stoi(s.substr(l));
                    bool isGood = true;
                    
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<string> ans = restoreIpAddresses("2334456");
    for(string s: ans) {
        cout << s << endl;
    }
}