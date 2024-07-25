#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
	void merge(int start, int mid, int end, vector<int>&nums) {
		int i = start;
		int j = mid + 1;
		vector<int> temp;
		while(i <= mid && j <= end) {
			if(nums[i] <= nums[j]) {
				temp.push_back(nums[i]);
				i++;
			} else {
				temp.push_back(nums[j]);
				j++;
			}
		}
		while(i <= mid) {
			temp.push_back(nums[i]);
			i++;
		}
		while(j <= end) {
			temp.push_back(nums[j]);
			j++;
		}
		for(int i = start; i <= end; i++) {
			nums[i] = temp[i - start];
		}
	}

	void mergeSort(int start, int end, vector<int>&nums) {
		int mid = (start + end) / 2;
		// cout << start << " " << mid << " " << end << endl;
		if (start >= end) {
			return;
		}
		mergeSort(start, mid, nums);
		mergeSort(mid + 1, end, nums);
		merge(start, mid, end, nums);
	}

	vector<int> sortArray(vector<int> &nums) {
		mergeSort(0, nums.size() - 1, nums);
		return nums;
	}
	
	void run() {
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<int> result = sortArray(v);
		for(int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
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