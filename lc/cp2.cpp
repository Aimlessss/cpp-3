#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getUnsetBit(int diff){
        int i = 0;
        while(diff > 0){
            if(diff & 1 == 1){
                break;
            }
            diff >>= 1;
            i++;
        }
        return i;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(auto x : nums){
            diff ^= x;
        }
        int k = getUnsetBit(diff);
        int mask = 1 << k;
        int a = 0;
        int b = 0;
        for(auto x : nums){
            if((x & mask) == 0){
                a ^= x;
            } else {
                b ^= x;
            }
        }
        return {a, b};
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = sol.singleNumber(nums);
    for(int x : result){
        cout << x << " ";
    }
    return 0;
}
