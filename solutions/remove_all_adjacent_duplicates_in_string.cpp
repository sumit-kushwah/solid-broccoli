#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here

string removeDuplicates(string s)
{
  stack<char> st;
  for (char ch : s)
  {
    if (st.empty() || st.top() != ch)
    {
      st.push(ch);
    }
    else
    {
      st.pop();
    }
  }
  string ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{

  return 0;
}