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

int main(){
    int n, k; 
    cin>>n>>k;
    seive();
    addPrimes();
    int count = 0;
    for(int i = 0; i < primes.size() - 1; i++){
        int num = primes[i] + primes[i + 1] + 1;
        if( num <= n && isPrime[num]){
            count++;
        }
    }
    if(count >= k){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}