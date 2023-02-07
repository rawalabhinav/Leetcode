#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	string multiply(string a, string b){
		int n = a.size(), m = b.size();
		
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		if (n < m) swap(n,m), swap(a,b);
		
		string ans = "";
	}
};
