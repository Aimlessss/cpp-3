#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, q;
	cin>>n>>q;
	int arr[n];
	for(int i = 0; i < n; i++){
	    cin>>arr[i];
	}
	sort(arr, arr + n);
	while(q--){
	    int x;
	    cin>>x;
	    int latest = 0;
	    int ans = 0;
	    for(int i = 0; i < n; i++){
	        if (i > 0 && arr[i] == arr[i-1]) continue;
	        if(latest < arr[i]){
	            ans+=x;
	        }else{
	            int temp = arr[i] + x;
	            ans+=temp - latest;
	        }
	        latest = arr[i] + x;
	    }
	}
	return 0;
}
