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
int D[N] = {0};
int F[N] = {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        sort(A, A + n);
        for (int i = 0; i < m; ++i) {
            cin >> D[i];
        }
        sort(D, D + m);
        for (int i = 0; i < k; ++i) {
            cin >> F[i];
        }
        int rg = -1;
        pair<int, int> mx = {LLONG_MIN, LLONG_MIN};
        for (int i = 1; i < n; ++i) {
            int df = A[i] - A[i - 1];
            if (df >= mx.first) {
                rg = i - 1;
                mx.second = mx.first;
                mx.first = df;
            } else if (df > mx.second) {
                mx.second = df;
            }
        }
        int st = A[rg], ed = A[rg + 1];
        int avg = (st + ed) / 2;
        for (int i = 0; i < k; ++i) {
            int x = avg - F[i];
            int idx = lower_bound(D, D + m, x) - D;
            for (int j = max(0ll, idx - 2); j < min(m, idx + 3); ++j) {
                int sum_ = F[i] + D[j];
                mx.first = min(mx.first, max(sum_ - st, ed - sum_));
            } 
        }
        cout << max(mx.first, mx.second) << endl;
    }
    return 0;
}