#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans = 0;
        for(int i = 0; i < 31; i++){
            int countBits = 0;
            for(int j = 0; j < n; j++){
                int bit = (a[j] >> i) & 1;
                countBits += bit;
            }
            if(countBits % 2 == 1){
                ans |= (1 << i);
            }
        }
        cout<<ans<<endl;
	}

}
