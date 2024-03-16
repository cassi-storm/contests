#include <bits/stdc++.h>
#define int long long
#define mod_ 1000000007
using namespace std;

int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
	    int n, q, sum_ = 0;
	    cin >> n >> q;
	    vector<int> a(n);
	    for (auto &i : a) {
	        cin >> i;
	        sum_ += i;
	    }
	    int l, r;
	    for (int i = 0; i < q; ++i) {
	        cin >> l >> r;
	        sum_ += (r - l + 1) % 2;
	    }
	    cout << sum_ << endl;
	}
	return 0;
}
