#include <bits/stdc++.h>
using namespace std;

vector <int> findSubstring(string s, vector <string>& words){
	int k = words[0].size(), n = words.size();
	
	multiset <string> m;
	for(auto&w: words) m.insert(w);
	
	vector <int> ans;
	//k * (n + (n / k) * k) = omega of (n *k)
	for(int i = 0; i < k; ++i){
		multiset <string> t;
		int l = i, r = i;
		
		for(int j = 0; j < n - 1; ++j, r += k){
			t.insert(s.substr(r, k));
		}
		
		for(; r < (int) s.size(); l += k, r += k){	
			t.insert(s.substr(r, k));;
			
			if (m == t) ans.emplace_back(l);
			t.erase(t.find(s.substr(l, k)));
		}		
	} return ans;
}
