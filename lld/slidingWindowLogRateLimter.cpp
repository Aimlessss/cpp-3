#include<bits/stdc++.h>
using namespace std;
#define ll long long

class slidingWindowLogRateLimter { 
    private : 
        ll maxRequest;
        ll timeLog;

        ll getCurrTime(){
            return chrono::duration_cast<chrono::seconds>(
                chrono::steady_clock::now().time_since_epoch()
            ).count();
        }
        unordered_map<string, deque<ll>>logs;
    public : 
        slidingWindowLogRateLimter(int maxReqs, int log){
            this->maxRequest = maxReqs;
            this->timeLog = log;
        }

        bool allow(const string& id){
            ll now = getCurrTime();
            deque<ll>& dq = logs[id];
            //removing experied reqs
            while(!dq.empty() && dq.front() <= now - timeLog){
                dq.pop_front();
            }

            //check curr req is valid or not
            if(dq.size() < maxRequest){
                dq.push_back(now);
                return true;
            }
            return false;
        }
};


int main(){

    slidingWindowLogRateLimter slg(5, 10);
    slg.allow("1");
    //call here
}