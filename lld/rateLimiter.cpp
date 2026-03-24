#include<bits/stdc++.h>
using namespace std;

class FixedWindowRateLimter { 
    private : 
        struct Window {
            int count;
            chrono::steady_clock::time_point start;
        };
        unordered_map<string, Window>store;
        int limit;
        int windowSizeSec;
        mutex mtx;
    public : 
        FixedWindowRateLimter(int inputLimts, int inputWindow){
            this->limit = inputLimts;
            this->windowSizeSec = inputWindow;
        }

        bool allow(const string key){
            auto now = chrono::steady_clock::now();
            lock_guard<mutex> lock(mtx);
            auto window = store[key];
            if(window.count == 0){
                window.start = now;
            }

            auto elapsed = chrono::duration_cast<chrono::seconds>(
                now - window.start
            ).count();

            if(elapsed >= windowSizeSec){
                window.count = 0;
                window.start = now;
            }

            if(window.count < limit){
                window.count++;
                return true;
            }

            return false;
        }

};

int main(){
    //call it here
}