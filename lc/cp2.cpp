#include <bits/stdc++.h>
using namespace std;


int binPow(int a, int b){
    int half = binPow(a, b / 2);
    int res = half * half;
    if(b % 2 == 1){
        res = (res * a);
    }
    return res;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n, m; 
	    cin>>n>>m;
	    int arr[n];
	    int sum = 0;
	    for(int i = 0;i < m; i++){
	        cin>>arr[i];
	    }
        int dounets = 0;
        for(int i = 0; i < m; i++){
            int pieces = m - (i + 1);
            dounets+=arr[i];

            if(dounets >= pieces - 1){
                if(dounets == pieces - 1){
                    cout<<pieces - 1<<endl;
                }else{
                    cout<<pieces<<endl;
                }
                break;
            }
        }
	}

}
