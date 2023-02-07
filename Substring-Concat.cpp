#include <bits/stdc++.h>
using namespace std;

#include "debug.h"

vector <int> findSubstring(string s, vector<string>& words){
	int k = words[0].size(), n = words.size();
	
	multiset <string> m;
	for(auto&w: words) m.insert(w);
	
	vector <int> ans;
	//k * (n + (n / k) * k) = omega of (n *k)
	for(int i = 0; i < k; ++i)
	{
		multiset <string> t;
		int l = i, r = i;
		
		for(int j = 0; j < n - 1; ++j){
			t.insert(s.substr(r, k));
			r += k;
		}
		
		while(r < (int) s.size()){	
			t.insert(s.substr(r, k));;
			
			if (m == t){
				ans.emplace_back(l);
			}
			
			auto it = t.find(s.substr(l, k));
			t.erase(it);
			
			l += k; r += k;
		}		
	}
	return ans;
}

signed main(){
	string s = "barfoothefoobarman";
	vector<string> words = {"foo","bar"};
	
	vector<int> ans =  findSubstring(s, words);
	debug(ans);
	
}