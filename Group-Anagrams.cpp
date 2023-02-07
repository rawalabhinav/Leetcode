#include <bits/stdc++.h>
using namespace std;

vector <vector <string>> groupAnagrams(vector <string>& s){
	vector <vector <string>> ans;
	
	map <string, vector <string>> m;
	for(string& w: s){
		string s(26, '`');
		
		for(char& c: w) ++s[c - 'a'];
		m[s].emplace_back(w);
	}
	
	for(auto&p: m) ans.push_back(p.second);
	return ans;
}

signed main(){
	vector<string> s ={
		"eat", "tea", "tan", "ate", "nat", "bat"
	};
	
	vector<vector<string>> ans = groupAnagrams(s);
}