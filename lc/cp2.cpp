#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n*=3;
        vector<int>v;
        int i = 1;
        int j = n;
        while(i < j){
            v.push_back(i);
            i++;
            v.push_back(j);
            j--;
            v.push_back(j);
            j--;
        }
        for(auto x : v){
            cout<<x<<" ";
        }
        cout<<endl; 
    }
	return 0;
}
