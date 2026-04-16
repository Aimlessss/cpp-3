#include <bits/stdc++.h>
using namespace std;
    int n;
    int solve(vector<int>& sameIdxVec, int queryIdx, int ele){
        int sz = sameIdxVec.size();
        if(sz == 1) return -1;

        int pos = lower_bound(begin(sameIdxVec), end(sameIdxVec), queryIdx) - begin(sameIdxVec);

        int res = INT_MAX;

        int right = sameIdxVec[(pos + 1) % sz];
        int d = abs(queryIdx - right);
        int circularD = n - d;
        res = min(res, min(d, circularD));

        int left = sameIdxVec[(pos - 1 + sz) % sz];
        d = abs(queryIdx - left);
        circularD = n - d;
        res = min(res, min(d, circularD));
        return res;
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int querySize = queries.size();
        unordered_map<int, vector<int>>mp;
        n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>q;
        for(int i = 0; i < queries.size(); i++){
            
            int ans = solve(mp[nums[queries[i]]], queries[i], nums[queries[i]]);
            q.push_back(ans);
        }
        return q;
    }

int main()
{
    vector<int> changed = {3,7,1,6};

    return 0;
}
