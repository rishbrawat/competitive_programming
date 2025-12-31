#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        if(!head) return nullptr;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return nullptr;

        slow = head;
        while(slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
       return slow;
    }
};