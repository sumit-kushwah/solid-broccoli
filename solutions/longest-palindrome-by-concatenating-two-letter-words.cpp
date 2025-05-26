#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // write your code
  int longestPalindrome(vector<string>& words) {
        // cout << words.size() << endl;
        unordered_map<string, int> umap;
        for(int i = 0; i < words.size(); i++) {
            if (umap.find(words[i]) != umap.end()) {
                umap[words[i]]++;
            } else {
                umap[words[i]] = 1;
            } 
        }
        // cout << umap.size() << endl;
        int ans = 0;
        int oddadd = false;
        // for (auto e = umap.begin(); e != umap.end(); e++) {
        //     cout << e->first << " " << e->second << endl;
        // }
        for (auto e = umap.begin(); e != umap.end(); e++) {
            string word = e->first;
            reverse(word.begin(), word.end());
            int freq1 = e->second;
            cout << e->first << " " << e->second << endl;
            int freq2 = 0;
            if (umap.find(word) != umap.end()) {
                freq2 = umap[word];
            }
            if (e->first == word) { // gg tt
                if (freq1 & 1) {
                    oddadd = true;
                    ans += (freq1 - 1) * 2;
                } else {
                    ans += freq1 * 2;
                }
            } else {
                ans += min(freq1, freq2) * 4;
                umap[word] = 0;
                umap[e->first] = 0;
            }
        }
        if (oddadd) {
            ans += 2;
        }
        return ans;
    }
    void run() {
        vector<string> words = {"oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"};
        cout << longestPalindrome(words);
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    Solution *s = new Solution();
    s->run();
    return 0;
}