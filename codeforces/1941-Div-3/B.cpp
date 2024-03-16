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
int A[N] =  {0};

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
        bool flag = true;
        for (int i = 2; i < n; ++i) {
            A[i] -= A[i - 2];
            A[i - 1] -= A[i - 2] * 2;
            A[i - 2] = 0;
            if (A[i] < 0 || A[i - 1] < 0) {
                flag = false;
                break;
            }
        }
        flag = flag && A[n - 2] == 0 && A[n - 1] == 0; 
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}