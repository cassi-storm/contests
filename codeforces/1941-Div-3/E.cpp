#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 101;
const int M = 2e5 + 10;

int A[M] = {0};
int C[M] = {0};
int K[N] = {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        d += 2;
        for (int row = 1; row <= n; ++row) {
            for (int i = 0; i < m; ++i) {
                cin >> A[i];
            }
            map<int, int> map_;
            map_[1] = 1;
            C[0] = 1;
            for (int i = 1; i < m; ++i) {
                if (i - d >= 0) {
                    int x = --map_[C[i - d]];
                    if (x <= 0) {
                        map_.erase(C[i - d]);
                    }
                }
                C[i] = 1 + A[i] + map_.begin()->first;
                ++map_[C[i]];
            }
            K[row] = K[row - 1] + C[m - 1];
        }
        int min_ = LLONG_MAX;
        for (int i = k; i <= n; ++i) {
            min_ = min(min_, K[i] - K[i - k]);
        }
        cout << min_ << endl;
    }
    return 0;
}