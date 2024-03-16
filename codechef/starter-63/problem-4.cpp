#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
        string s;
        cin >> s;
        int n = s.size(), cmax_ = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (n - i) * (i + 1) * (s[i] == '1' ? -1 : 1);
            cmax_ -= min(0ll, a[i]);
        }
        int sum_ = 0, max_ = 0;
        for (auto i : a) {
            if (sum_ < 0) 
               sum_ = 0;
           sum_ += i;
           max_ = max(max_, sum_);
        }
        cout << (cmax_ + max_) << endl;
	}
	return 0;
}
