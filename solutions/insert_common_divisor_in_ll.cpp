#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  // write your code
  int gcd(int a, int b) {
    if (a == 0) {
      return b;
    }
    return gcd(abs(b - a), min(a, b));  
  }

  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode* orgHead = head;
    while(head->next != nullptr) {
      int gcd_value = gcd(head->val, head->next->val);
      ListNode* newHead = new ListNode(gcd_value);
      newHead->next = head->next;
      head->next = newHead;  
      head = newHead->next;
    }
    return orgHead;
  }
  void run()
  {
  }
};

int main()
{
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  Solution *s = new Solution();
  s->run();
  return 0;
}