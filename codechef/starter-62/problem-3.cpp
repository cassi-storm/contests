#include <bits/stdc++.h>
#define int long long
#define mod_ 1000000007
#define endl "\n"
using namespace std;

int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
	    int n, index = 0;
	    string s;
	    cin >> n >> s;
	    if (n == 1) {
	        cout << 0 << endl;
	        continue;
	    }
	    vector<char> a;
	    a.push_back(s[0]);
	    for (int i = 1; i < n; ++i) {
	        if (a[index] != s[i]) {
	            a.push_back(s[i]);
	            ++index;
	        }
	    }
	    if (a.size() % 2 == 0) {
	        if (a[0] == '0') {
	            cout << (a.size() / 2 - 1) << endl;
	        } else {
	            cout << (a.size() / 2) << endl;
	        }
	    } else {
            cout << (a.size() / 2) << endl;
	    }
	}
	return 0;
}
