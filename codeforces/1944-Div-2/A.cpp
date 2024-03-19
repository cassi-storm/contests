#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;


int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k >= n - 1) {
            cout << 1 << endl;
        } else {
            cout << n << endl;
        }
    }
    return 0;
}