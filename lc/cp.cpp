#include<bits/stdc++.h>
using namespace std;

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int prevStart = points[0][0];
        int prevEnd = points[0][1];
        int count = 0;
        for(int i = 1; i < points.size(); i++){
            int currStart = points[i][0];
            int currEnd = points[i][1];
            if(currStart > prevEnd){
                count++;
                prevStart = currStart;
                prevEnd = currEnd;
            }else{
                prevStart = max(prevStart, currStart);
                prevEnd = min(prevEnd, currEnd);
            }
        }
        return count;
    }

int main(){
    vector<int>v = {4,5,2,1};
    vector<int>q = {3, 10, 21};

}