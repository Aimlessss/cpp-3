#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<bool>isPrime;
    void seive(int maxEle){
        isPrime.assign(maxEle + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= maxEle; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= maxEle; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        map<int, vector<int>>mp;
        int n = nums.size();
        int maxEle = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
            maxEle = max(maxEle, nums[i]);
        }
        seive(maxEle);
        vector<bool>vis(n, false);
        queue<int>q;
        q.push(0);
        vis[0] = true;
        int count = 0;
        set<int>seen;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int idx = q.front(); q.pop();
                if(idx == n - 1)return count;
                if(idx - 1 >= 0 && !vis[idx - 1]){
                    q.push(idx - 1);
                    vis[idx - 1] = true;
                }

                if(idx + 1 <= n - 1 && !vis[idx + 1]){
                    q.push(idx + 1);
                    vis[idx + 1] = true;
                }

                if(!isPrime[nums[idx]] || seen.count(nums[idx])) continue;
                seen.insert(nums[idx]);

                for(int multi = nums[idx]; multi <= maxEle; multi += nums[idx]){
                    if(!mp.count(multi)){
                        continue;
                    }
                    for(auto& j : mp[multi]){
                        if(!vis[j]){
                            vis[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
            count++;
        }
        return count;
    }
};
int main(){
    vector<int> nums = {
        2, 2, 2, 2, 2
    };
    Solution sol;
    cout << sol.minJumps(nums) << endl;
}