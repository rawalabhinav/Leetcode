#include <bits/stdc++.h>
using namespace std;

vector <int> twoSum(vector<int>& a, int target) {
    unordered_map <int,int> m;
    
    for(int i = 0;i < (int) a.size(); ++i){
        if(m.count(target - a[i]))            
            return {m[target - a[i]], i};
        
        m[a[i]] = i;
    }
    return {};  
}