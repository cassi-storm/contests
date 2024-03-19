#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
    
const int N = 2e5 + 10;
int A[N] = {0};
    
int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        } 
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (A[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        if (A[l] == x) {
            cout << 0 << endl;
            continue;
        }
        int idx = 0;
        for (int i = 1; i <= n; ++i) {
            if (A[i] == x) {
                idx = i;
                break;
            }
        }
        cout << 1 << endl << idx << " " << l << endl;
    }
    return 0;
}