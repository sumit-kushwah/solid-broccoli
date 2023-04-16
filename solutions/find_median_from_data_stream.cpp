#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// write your function here

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue <int, vector<int>, greater<int> > min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (min_heap.empty()) {
          min_heap.push(num);
          return;
        }
        if (min_heap.size() > max_heap.size()) {
          if (num < min_heap.top()) {
            max_heap.push(num);
          } else {
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(num);
          }
        } else {
          if (num < min_heap.top()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(num);
          } else {
            min_heap.push(num);
          }
        }
    }
    
    double findMedian() {
        int max_heap_size = max_heap.size();
        int min_heap_size = min_heap.size();
        if (min_heap_size > max_heap_size)
          return (double)min_heap.top();
        return (double)(((double)min_heap.top() + (double)max_heap.size()) / 2);
    }
};


int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  
  return 0;
}