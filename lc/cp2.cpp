#include <bits/stdc++.h>
using namespace std;

    int reverseNumber(int n){
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int minLen = INT_MAX;
        for(int i = 0; i < n; i++){
            int reverseNo = reverseNumber(nums[i]);
			if(mp.find(nums[i]) == mp.end() && mp.find(reverseNo) == mp.end()){
				mp[nums[i]] = i;
				mp[reverseNo] = -1;
			}else{
				mp[nums[i]] = i;
					if(mp[nums[i]] > mp[reverseNo]){
					minLen = min(minLen, abs(mp[reverseNo] - mp[nums[i]]));
				}
			}
        }
		if(minLen == INT_MAX) return -1;
        return minLen;
    }

int main() {
	// your code goes here
	vector<int> nums = {21, 120};
	cout<<'b' - 96;

	return 0;
}
