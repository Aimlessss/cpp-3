#include <bits/stdc++.h>
using namespace std;
#define ll long long

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ll getLinkedListSize(ListNode* head){
        ll size = 0;
        while(head != nullptr){
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        //pop the last node 
        //attach the last node to first
        int size = getLinkedListSize(head);
        int toRotate = k % size;
        while (toRotate--){
            ListNode* prevOfLast = nullptr;
            ListNode* lastNode = head;
            while (lastNode->next != nullptr){
                prevOfLast = lastNode;
                lastNode = lastNode->next;
            }
            prevOfLast->next = nullptr;
            lastNode->next = head;
            head = lastNode;
        }
        return head;
    }
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next->next = new ListNode(7);
    Solution s;
    s.rotateRight(head, 2);
    ListNode* tail = head->next->next->next->next->next->next;
    ListNode* prevTail = head->next->next->next->next->next;
    prevTail->next = nullptr;
    tail->next = head;
    
    return 0;

}
