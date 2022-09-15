#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // write your function code here
  vector<int> findOriginalArray(vector<int>& changed) {
	vector<int> ans;
	if (changed.size() & 1) return ans;
	sort(changed.begin(), changed.end());
	queue<int> q;
	for (int e: changed) {
		if (q.empty() || q.front() != e) {
			ans.push_back(e);
			q.push(2 * e);
		} else {
			q.pop();
		}
	}
	if (!q.empty()) return {};	
	return ans;
  }
  void run()
  {
    // auto ans = this->function();
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