#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int k, n;
	    cin>>n>>k;
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    set<int>st;
	    int sub = n - k;
	    if(sub == 1){
	        for(int i = 0; i < n; i++){
	            st.insert(arr[i]);
	        }
	    }else{
	        int i = 0;
	        int j = sub - 1;
	        while(j < n){
	            int floorVal = floor((i + j) / 2);
	            st.insert(arr[floorVal]);
	            i++;
	            j++;
	        }
	    }
        for(auto it : st){
            cout<<it<<" ";
        }
	}
	return 0;
}
