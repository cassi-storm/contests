#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 110;
int A[N] =  {0};
int B[N] =  {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        int cnt = 0;
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> B[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i] + B[j] <= k) {
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}