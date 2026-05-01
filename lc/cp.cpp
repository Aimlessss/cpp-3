#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>>minHeapOne;
        priority_queue<int, vector<int>, greater<int>>minHeapTwo;

		int n = costs.size();
		int i = 0;
		int j = n - 1;
		int hired = 0;
		int ans = 0;
		while(hired < k){
			while(minHeapOne.size() < candidates && i<=j){
				minHeapOne.push(costs[i]);
				i++;
			}
			while(minHeapTwo.size() < candidates && i >= j){
				minHeapTwo.push(costs[i]);
				j++;
			}

			int minHeapOneEle = minHeapOne.size() > 0 ? minHeapOne.top() : INT_MAX;
			int minHeapTwoEle = minHeapTwo.size() > 0 ? minHeapTwo.top() : INT_MAX;

			if(minHeapOneEle <= minHeapTwoEle){
				ans += minHeapOneEle;
				minHeapOne.pop();
			}else{
				ans+= minHeapTwoEle;
				minHeapTwo.pop();
			}
			hired++;
		}
		return ans;
    }
};


int main() {
	Solution s;
	vector<int>v = {1,2,4,1};
	cout<<s.totalCost(v, 3, 3);	
}
