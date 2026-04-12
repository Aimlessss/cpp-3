#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrime(int number){
        if(number <= 1) return false;
        if(number == 2)return false;
        if(number % 2 == 0)return false;

        for(int i = 3; i * i <= number; i+=2){
            if(number % i == 0)return false;
        }
        return true;
    }
    int check(int number, int idx){
        int count = 0;
        if(idx % 2 == 0 && !isPrime(number)){
            while(!isPrime(number)){
                count++;
                number++;
            }
            return count;
        }else if(idx % 2 != 0 && isPrime(number)){
            while(isPrime(number)){
                count++;
                number++;
            }
            return count;
        }
        return count;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int counter = 0;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            counter+=(check(nums[i], i));
        }
        return counter;
    }
};


int main(){
    vector<int> nums = {1,2,3,4};
    Solution sol; 
    cout << sol.minOperations(nums) << endl;

}   