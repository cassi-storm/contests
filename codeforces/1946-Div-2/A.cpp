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
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        sort(A, A + n);
        int x = n / 2 - (n % 2 == 0);
        int p = A[x] + 1, cnt = 0;
        for (int i = x; i < n; ++i) {
            if (A[i] < p) {
                cnt += p - A[i];
                A[i] = p;
            } else {
                break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}