#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
    
const int N = 3e5 + 10;
int C[N] = {0};
    
int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
            } 
        }
        int zr = 0, os = cnt;
        int idx = (n - cnt) <= cnt ? 0 : n;
        int min_ = (n + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '1') {
                --os;
            } else {
                ++zr;
            }
            bool left = zr >= (i + 1) / 2;
            bool right = os >= (n - i + 1) / 2;
            int x = abs(n - 2 * i) / 2;
            if (left && right && x < min_) {
                min_ = x;
                idx = i;
            }
        }
        cout << idx << endl;
    }
    return 0;
}