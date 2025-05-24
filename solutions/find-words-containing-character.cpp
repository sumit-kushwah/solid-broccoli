#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // write your code
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); i++) {
            string s = words[i];
            for(char ch: s) {
                if (ch == x) { 
                    ans.push_back(i);
                    break;
                }
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