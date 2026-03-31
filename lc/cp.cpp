#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        this->val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>>res;
    void solve(int target, int i, int j, vector<int>& nums){
        while(i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }else{
                while(i < j && nums[i] == nums[i + 1]) i++;
                while(i < j && nums[j] == nums[j + 1]) j++;
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int n1 = nums[i];
            int target = -n1;
            solve(target, i + 1, n - 1, nums);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int>v = {-1,0,1,2,-1,-4};
    s.threeSum(v);
}