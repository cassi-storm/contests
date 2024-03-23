#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 1e5 + 10;
int A[N] = {0};
int P[N] = {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        P[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            P[i] = P[i - 1] ^ A[i];
        }
        ++x;
        int max_ = -1;
        for (int shift = 31; shift > -1; --shift) {
            int bit = 1 << shift;
            int or_ = (x ^ bit) | (bit - 1);
            or_ = ~or_;
            if ((x & bit) == 0 || (P[n] & or_)) {
                continue;
            }
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                if (P[i] & or_) {
                    continue;
                }
                ++cnt;
            }
            max_ = max(max_, cnt);
        }
        cout << max_ << endl;
    }
    return 0;
}
