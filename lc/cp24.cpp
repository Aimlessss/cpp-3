#include <bits/stdc++.h>
using namespace std;
    #define ll long long
    // 1 3 9 13
    bool check(ll midd, vector<int>& nums, ll k, vector<int> pref){
        int i = 0;
        int j = midd - 1;
        while(j < nums.size()){
            int targetIdx = (i + j) / 2;
            int target = nums[targetIdx];
            int opsLeft = 0;
            int opsRight = 0;
            if(targetIdx == 0){
                opsLeft = 0;
            }else{
                opsLeft = abs(((targetIdx - i) * target) - (pref[targetIdx - 1] - ( i > 0 ? pref[i - 1] : 0)));
            }

            opsRight = abs(((j - targetIdx) * target) - (pref[j] - pref[targetIdx]));

            if(opsLeft + opsRight <= k){
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        ll left = 1;
        ll right = n;
        sort(nums.begin(), nums.end());
        vector<int>pref(n, 0);
        pref[0] = nums[0];
        for(int i = 0; i < n; i++){
            pref[i] = pref[i - 1] + nums[i];
        }
        ll result = left;
        while(left <= right){
            ll midd = left + (right - left) / 2;
            if(check(midd, nums, k, pref)){
                left = midd + 1;
                result = midd;
            }else{
                right = midd - 1;
            }
        }
        return result;
    }
int main()
{
    vector<int> changed = {1,2,6,4};
    ll k = 3;
    cout << maxFrequencyScore(changed, k) << endl;

    return 0;
}
