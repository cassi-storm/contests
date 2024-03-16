#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;


const int N = 5e3 + 10;
int D[N][N] = {0};


int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        string A;
        cin >> A;
        int n = A.size();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                D[i][j] = 0;
            }
        }
        int max_ = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (A[i - 1] == A[j - 1] || A[i - 1] == '?' || A[j - 1] == '?') {
                    D[i][j] = D[i - 1][j - 1] + 1;
                    int x = min(j - i, D[i][j]);
                    if (x > max_) {
                        int idx = j - x;
                        if (idx == i) {
                            max_ = x;
                        }
                    }
                }
            }
        }
        max_ = max_ * 2;
        cout << max_ << endl;
    }
    return 0;
}