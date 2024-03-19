#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 2e5;
int A[N] = {0};
int C[N] = {0};
int L[N] = {0};
int R[N] = {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> map_;
        for (int i = 0; i < 2 * n; ++i) {
            cin >> A[i];
            C[i] = 0;
        }        
        for (int i = 0; i < n; ++i) {
            ++C[A[i]];
        }
        int lx = 0, rx = 0;
        for (int i = 1; i <= n; ++i) {
            if (C[i] == 2) {
                L[lx++] = i;
                L[lx++] = i;
            }
            if (C[i] == 0) {
                R[rx++] = i;
                R[rx++] = i;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (lx >= 2 * k) {
                break;
            }
            if (C[i] == 1) {
                L[lx] = i;
                R[lx++] = i;
            }
        }
        for (int i = 0; i < 2 * k; ++i) {
            cout << L[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 2 * k; ++i) {
            cout << R[i] << " ";
        }
        cout << endl;
    }
    return 0;
}