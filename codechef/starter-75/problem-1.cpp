#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ones = 0;
		for (auto i : s) {
			i == '1' && ++ones;	
		}
		if (ones > 3) {
			cout << "NO" << endl;
			continue;
		}
		if (ones == 3 || ones == 2) {
			cout << "YES" << endl;
			continue;
		}
		if (ones == 1) {
			cout << (s[n - 1] == '1' || s[n - 2] == '1' ? "NO" : "YES") << endl;	
			continue;
		}
		cout << "NO" << endl;
	}
	return 0;	
}
