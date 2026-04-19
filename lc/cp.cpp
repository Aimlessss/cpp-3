#include<bits/stdc++.h>
using namespace std;

// templates 
const int MAXN = 100000;
vector<bool>isPrime(MAXN + 1, true);
vector<int>primes;
void seive(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= MAXN; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= MAXN; j+=i){
                isPrime[j] = false;
            }
        }
    }

}
void addPrimes(){
    for(int i = 2; i <= MAXN; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}
void solve(int idx, int n){
    int count = 1;
    
}
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        if(isPrime[i]){
            solve(i, n);
        }
    }
    return 0;
}