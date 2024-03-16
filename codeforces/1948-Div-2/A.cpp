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
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        n /= 2;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                cout << "AA";
            } else {
                cout << "BB";
            }
        }
        cout << endl;
    }
    return 0;
}