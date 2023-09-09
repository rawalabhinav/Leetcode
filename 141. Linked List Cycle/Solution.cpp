#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    const int smol = -1 -1e5;
    bool hasCycle(ListNode *head) {
        for(; head != NULL; head = head -> next){
            if (head -> val == smol){
                return true;
            }

            head -> val = smol;
        }

        return false;
    }
}; 