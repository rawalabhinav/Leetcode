#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev = NULL;

        for(int i = 1; i < left; ++i){
            prev = start;
            start = start -> next;
            end = end -> next;
        }

        ListNode* savedprev = prev;
        ListNode* cur = end;

        for(int i = left; i < right; ++i){
            end = end -> next;
            cur -> next = prev;
            prev = cur;
            cur = end;
        }
        
        start -> next = end -> next;
        cur -> next = prev;

        if (savedprev) savedprev -> next = end;
        else return end;
        return head;

    }
};