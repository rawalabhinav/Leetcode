#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0, 0);
        ListNode* right = new ListNode(0, 0);

        ListNode* l = left;
        ListNode* r = right;

        for(ListNode* cur = head; cur != NULL; cur = cur -> next){
            if (cur -> val < x){
                l -> next = cur;
                l = cur;
            } else {
                r -> next = cur;
                r = cur; 
            }
        }

        l -> next = right -> next;
        r -> next = NULL;
        
        return left -> next;
    }
};