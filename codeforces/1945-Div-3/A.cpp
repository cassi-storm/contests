#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
    
const int N = 4e5 + 10;
char S[N] = {0};
int R[N] = {0};
    
int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int tents = a + b / 3;
        if (b % 3 != 0 && (3 - b % 3) > c) {
            cout << -1 << endl;
            continue;
        }
        if (b % 3 != 0) {
            c -= 3 - b % 3;
            tents += 1;
        }
        tents += c / 3 + (c % 3 != 0);
        cout << tents << endl;
    }
    return 0;
}