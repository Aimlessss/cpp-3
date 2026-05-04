#include <bits/stdc++.h>
using namespace std;
#define ll long long

int bs(vector<ll>& arr, ll target){
    int left = 0; 
    int right = arr.size() - 1;
    int idx = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] <= target){
            idx = mid;
            target+=arr[mid];
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return idx;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n);
        vector<ll>brr;
        for(ll i = 0; i < n; i++){
            cin>>arr[i];
        }
        brr = arr;
        // sort(arr, arr + n);
        sort(arr.begin(), arr.end());
        vector<ll>pref(n, 0);
        map<ll, ll>mp;
        pref[0] = arr[0];
        mp[arr[0]] = arr[0];
        for(ll i = 1; i < n; i++){
            pref[i] = pref[i - 1] + arr[i];
            mp[arr[i]] = pref[i];
        }
        vector<ll>ans; 
        for(ll i = 0; i < n; i++){
            ll num = brr[i];
            ll prefSumEle = mp[num];
            ll temp = bs(arr, prefSumEle);
            ans.push_back(temp - 1);
        }

        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
	}
}
