#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for(ListNode* i = head; i != NULL; ++n, i = i -> next);

        vector <ListNode*> ans(k);
        k = min(n, k);
        
        if (n == 0) return ans;
        
        int span = n / k, rem = n % k;
        for(int i = 0; i < k; ++i){
            ans[i] = head;

            ListNode* prev = head;
            for(int j = 0; head && j < span + bool(rem); ++j){
                prev = head;
                head = head -> next;
            }

            if (rem) --rem;
            if (prev) prev -> next = NULL;
            
        }

        return ans;
    }
};