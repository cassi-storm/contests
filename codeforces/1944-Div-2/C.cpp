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
int M[N] = {0};
int C[N] = {0};
int X[N] = {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, x = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            X[i] = 0;
            M[i] = 0;
        }
        X[n] = 0;
        for (int i = 0; i < n; ++i) {
            ++M[A[i]];
        }
        sort(A, A + n, [](int a, int b) {
            if (M[a] == M[b]) {
                return a < b;
            }
            return M[a] < M[b];
        });
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                C[x++] = A[i];
                X[A[i]] = 1;
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (X[i] == 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}