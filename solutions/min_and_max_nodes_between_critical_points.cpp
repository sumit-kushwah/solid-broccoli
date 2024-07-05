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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critic_location;
        int prev = head->val;
        head = head->next;
        int i = 1;
        while(head->next != nullptr) {
            int cur = head->val;
            int next_val = head->next->val;
            if (cur > prev && cur > next_val) {
                critic_location.push_back(i);
            }
            if (cur < prev && cur < next_val) {
                critic_location.push_back(i);
            }
            prev = head->val;
            head = head->next;
            i++;
        }
        if (critic_location.size() < 2) {
            return {-1, -1};
        }
        int minv = INT_MAX;
        int maxv = critic_location.back() - critic_location[0];
        for(int i = 0; i < critic_location.size() - 1; i++) {
            minv = min(minv, critic_location[i + 1] - critic_location[i]);
        }
        return {minv, maxv};
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