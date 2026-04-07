#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    list<int>ls;
    map<int, pair<list<int>::iterator, int>>mp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    void update(int key){
        ls.erase(mp[key].first);
        ls.push_front(key);
        mp[key].first = ls.begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        update(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            update(key);
            mp[key].second = value;
        }else{
            ls.push_front(key);
            mp[key].first = ls.begin();
            mp[key].second = value;
            n--;
        }
        if(n < 0){
            int lr = ls.back();
            ls.pop_back();
            mp.erase(lr);
            n++;
        }
    }
};

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        map<int, set<int>>mp;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 9; j < n; j++){
                mp[i - j].insert(matrix[i][j]);
            }
        }
        if(mp.size() > m + n)return false;
        for(auto x : mp){
            if(x.second.size() > 1){
                return false;
            }
        }
        return true;
    }
int main(){
    vector<vector<int>>matrix = {{1, 2}, {2,2}};
    cout << isToeplitzMatrix(matrix) << endl;
}