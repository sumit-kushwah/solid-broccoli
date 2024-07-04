#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // write your code
	ListNode* mergeNodes(ListNode* head) {
		ListNode* ans = new ListNode(0);
		ListNode* org = ans;
		int i = 0;
		while(head->next != nullptr) {
			if (head->val == 0) {
				if (head->next != nullptr && i != 0) {
					ans->next = new ListNode(0);
					ans = ans->next;
				}
			} else {
				ans->val += head->val;
			}
			head = head->next;
			i++;
		}
		return org;
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