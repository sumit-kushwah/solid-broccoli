#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  string getMorseCode(string word) {
    vector<string> morseStrings = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string morseCode = "";
    for (char ch: word) {
      int index = ch - 'a';
      string charMorse = morseStrings[index];
      morseCode += charMorse;
    }
    return morseCode;
  }
  int uniqueMorseRepresentations(vector<string>& words) {
      set<string> s;
      for (string word: words) {
        s.insert(getMorseCode(word));
      }
      return s.size();
  }
  void run()
  {
    vector<string> v = {"gin","zen","gig","msg"};
    auto ans = this->uniqueMorseRepresentations(v);
    this->printAnswer(ans);
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