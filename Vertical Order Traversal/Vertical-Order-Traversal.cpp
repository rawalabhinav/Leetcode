#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    public:
  
    vector <vector<int>> verticalTraversal(TreeNode* root) {
        map <int, vector <vector<int>>> m;
        vector <vector <int>> ans;

        queue <tuple <TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        int r = 0, c = 0;
        TreeNode* head = 0;

        while(!q.empty()){
            tie(head, r, c) = q.front();
            q.pop();

            if (!head) continue;
            m[c].push_back({r, head -> val});

            q.push({head -> left, r + 1, c - 1});
            q.push({head -> right, r + 1, c + 1});
        }

        vector <vector <int>> col;
        for(auto &p: m){
            tie(c, col) = p;

            sort(col.begin(), col.end());
            vector <int> temp;

            for(auto& v: col) temp.emplace_back(v[1]);
            ans.push_back(temp);
            
        }
        return ans;
    }
};