#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& nums, vector<int>curr, int start){
            res.push_back(curr);

        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            solve(res, nums, curr, start + 1);
            curr.pop_back();
            solve(res, nums, curr, start + 1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        solve(res, nums, curr, 0);
        return res;
    }
};

int main() {
    // your code goes here

}

// 2 2 3 1 3 3 1 2
// 2 2 2 1 3 3 1 2