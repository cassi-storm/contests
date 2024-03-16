#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 1e3;
int A[N] = {0};
int B[N] = {0};

int32_t main() {
    fastIO;
    int t;
    B[0] = 100;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        int x = 1;
        bool flag = true;
        for (int i = n - 1; i > -1; --i) {
            if (A[i] <= B[x - 1]) {
                B[x++] = A[i];
            } else {
                int t = A[i];
                vector<int> v;
                while (t) {
                    v.push_back(t % 10);
                    t /= 10;
                }
                for (auto i : v) {
                    if (i <= B[x - 1]) {
                        B[x++] = i;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}