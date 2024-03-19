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
int B[N] = {0};
int D[2][N] = {0};
    
int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> B[i];
        }
        int x = n + 1;
        D[0][x] = D[1][x] = 0;  
        for (int i = n; i > 0; --i) {
            D[0][i] = A[i] + min(D[0][i + 1], D[1][i + 1]);
            D[1][i] = B[i] + min(D[0][i + 1], D[1][i + 1]);
        }
        int min_ = LLONG_MAX;
        for (int i = 1; i <= m; ++i) {
            min_ = min(min_, D[0][i]);
        }
        cout << min_ << endl;
    }
    return 0;
}