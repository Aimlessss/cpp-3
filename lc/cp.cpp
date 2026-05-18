#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        vector<int>vis(n, false);

        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                int frontIdx = q.front(); q.pop();
                if(arr[frontIdx] == 0)return true;

                int newIdxPos = frontIdx + arr[frontIdx];
                int newIdxNeg = arr[frontIdx] - frontIdx;

                if(!(newIdxNeg < 0 || newIdxNeg >= arr.size() || vis[newIdxNeg])){
                    q.push(newIdxNeg);
                    vis[newIdxNeg] = true;
                };

                if(!(newIdxPos < 0 || newIdxPos >= arr.size() || vis[newIdxPos])){
                    q.push(newIdxPos);
                    vis[newIdxPos] = true;  
                };
            }
        }
        return false;
    }
};


int main() {
    // vector<int>v = {3, 2, 1, 0, 4};

    //[4,2,3,0,3,1,2], start = 5

    Solution s;
    vector<int>v = {4,2,3,0,3,1,2};
    s.canReach(v, 5);
}