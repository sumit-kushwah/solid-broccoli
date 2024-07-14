#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isNumber(string s) {
        for(char ch: s) {
            if (ch >= '0' && ch <= '9') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    string formulaMultiply(string s, int n) {
        string finalans = "";
        string ans = "";
        string num = "";
        for(char ch: s) {   
            if (ch >= '0' && ch <= '9') {
                num.push_back(ch);
            } else {
                if(ch >= 'A' && ch <= 'Z') {
                    if (ans != "" && num == "") {
                        finalans += ans + to_string(n);
                    }
                    if (ans != "" && num != "") {
                        finalans += ans + to_string(stoi(num) * n);
                    }
                    ans = "";
                    num = "";
                }
                ans.push_back(ch);
            }
        }
        if (ans != "" && num == "") {
            finalans += ans + to_string(n);
        }
        if (ans != "" && num != "") {
            finalans += ans + to_string(stoi(num) * n);
        }
        return finalans;
    }
    string sortAns(string s) {
        map<string, int> m;
        string ans = "";
        string num = "";
        for(char ch: s) {   
            if (ch >= '0' && ch <= '9') {
                num.push_back(ch);
            } else {
                if(ch >= 'A' && ch <= 'Z') {
                    if (ans != "" && num == "") {
                        m[ans] += 1;
                    }
                    if (ans != "" && num != "") {
                        m[ans] += stoi(num);
                    }
                    ans = "";
                    num = "";
                }
                ans.push_back(ch);
            }
        }
        if (ans != "" && num == "") {
            m[ans] += 1;
        }
        if (ans != "" && num != "") {
            m[ans] += stoi(num);
        }
        map<string, int>::iterator it = m.begin();
        string finalans = "";
        // Iterate through the map and print the elements
        while (it != m.end()) {
            finalans += it->first;
            if (it->second > 1) {
                finalans += to_string(it->second);
            }
            ++it;
        }
        return finalans;
    }
    string countOfAtoms(string formula) {
        formula = "(" + formula + ")";
        stack<string> st;
        bool isLastNumber = false;
        for(int i = 0; i < formula.size(); i++) {
            string temp = "";
            if (formula[i] == '(') {
                temp = "(";
                isLastNumber = false;
            } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
                temp.push_back(formula[i]);
                isLastNumber = false;
            } else if (formula[i] >= 'a' && formula[i] <= 'z') {
                temp = st.top();
                temp.push_back(formula[i]);
                st.pop();
                isLastNumber = false;
            } else if (formula[i] >= '0' && formula[i] <= '9') {
                if (isLastNumber) {
                    temp = st.top();
                    temp.push_back(formula[i]);
                    st.pop();
                } else {
                    temp.push_back(formula[i]);
                }
                isLastNumber = true;
            } else if (formula[i] == ')') {
                isLastNumber = false;
                while(st.top() != "(") {
                    cout << st.top() << endl;
                    if (isNumber(st.top())) {
                        int num = stoi(st.top());
                        cout << num << endl;
                        st.pop();
                        temp += formulaMultiply(st.top(), num);
                    } else {
                        temp += st.top();
                    }
                    st.pop();
                    // cout << temp << endl;
                }
                st.pop();
            }
            st.push(temp);
            cout << temp << " "  << st.size() << endl;
        }
        cout << st.top() << endl;
        return sortAns(st.top());
    }

    void run() {
      cout << countOfAtoms("K4(ON(SO3)2)2") << endl;
    }
};

int main() {
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  Solution *s = new Solution();
  s->run();
  return 0;
}