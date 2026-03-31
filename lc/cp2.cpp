#include<bits/stdc++.h>
using namespace std;
        map<int,int>unqiueMap;
        map<int, multiset<int>, greater<int>> eventPriorityMap;
class EventManager {
public:
        // map<int,int>unqiueMap;
        // map<int, multiset<int>, greater<int>> eventPriorityMap;
    EventManager(vector<vector<int>>& events) {
        for(int i = 0; i < events.size(); i++){
            int eventId = events[i][0];
            int priority = events[i][1];
            unqiueMap[eventId] = priority;
            eventPriorityMap[priority].insert(eventId);
        }

    }
    
    void updatePriority(int eventId, int newPriority) {
        int currPriority = unqiueMap[eventId];
        multiset<int>set = eventPriorityMap[currPriority];
        auto it = set.find(eventId);
        if(it != set.end()){
            set.erase(it);
        }
        eventPriorityMap[currPriority] = set;
        unqiueMap[eventId] = newPriority;
        multiset<int>newPrioritySet = eventPriorityMap[newPriority];
        newPrioritySet.insert(eventId);
    }
    
    int pollHighest() {
        auto it = eventPriorityMap.begin();

        int largestKey = it->first;
        multiset<int>& values = it->second;
        int ans = -1;
        if(!values.empty()){
            ans = *values.begin();
            unqiueMap.erase(ans);
            values.erase(ans);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> events = {{5, 7}, {2, 7}, {9, 4}};
    EventManager em(events);
    cout<<em.pollHighest()<<endl;
    em.updatePriority(9, 7);
    cout<<em.pollHighest()<<endl;
    cout<<em.pollHighest()<<endl;
}