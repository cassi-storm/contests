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
	    int a, b;
	    cin >> a >> b;
	    if (a > b) {
	        cout << "NO" << endl;
	        continue;
	    }
	    if (b - a >= a || a == b) {
	        cout << "YES" << endl;
	    } else {
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
