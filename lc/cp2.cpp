#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool check(int target, vector<vector<int>>& tasks){
        for(int i = 0; i < tasks.size(); i++){
            int first = tasks[i][0];
            int second = tasks[i][1];

            if(target < second)return false;
            target-=first;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int maxSecond = 0;
        int prefSum = 0;
        for(auto& x : tasks){
            prefSum+=x[0];
            maxSecond = max(maxSecond, x[1]);
        }
        sort(tasks.begin(), tasks.end());
        int left = 1;
        int right = maxSecond + prefSum;
        int res = right;
        while(left <= right){
            int midd = left + (right - left) / 2;

            if(check(midd, tasks)){
                res = midd;
                right = midd - 1;
            }else{
                left = midd + 1;
            }
        }
        return res;
    }
};

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll temp = n;
        ll arr[n];
        for(ll i = 0; i < n; i++){
            cin>>arr[i];
        }
        stack<ll>factors;
        for(ll i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                factors.push(i);
                if(n / i != i){
                    factors.push(n / i);
                }
            }
        }
        ll maxRes = 0;
        while(!factors.empty()){
            temp = factors.top();
            factors.pop();
            ll i = 0;
            ll j = 0;
            ll maxNum = LONG_LONG_MIN;
            ll minNum = LONG_LONG_MAX;
            ll currSum = 0;
            while(j < n){
                currSum+=arr[j];
                if(j - i + 1 >= temp){
                    maxNum = max(maxNum, currSum);
                    minNum = min(minNum, currSum);
                    currSum = 0;
                    i = j + 1;
                }
                j++;
            }
            maxRes = max(maxRes, abs(maxNum - minNum));
        }
        cout<<maxRes<<endl;
    }
    return 0;
}
