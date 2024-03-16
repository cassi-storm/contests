#include <bits/stdc++.h>
#define int long long
#define mod_ 1000000007
using namespace std;

int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    vector<int> a(n);
	    unordered_map<int, int> map_;
	    for (int i = 0; i < n; ++i) {
	        cin >> a[i];
	        ++map_[a[i] >> 1];
	    }
	    int max_ = 0;
	    for (auto i : map_) {
	        max_ = max(max_, i.second);
	    }
	    cout << (n - max_) << endl; 
	}
	return 0;
}
