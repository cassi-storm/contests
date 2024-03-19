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
        int a, b, m;
        cin >> a >> b >> m;
        ++m;
        int ah = (m / a) + (m % a != 0);
        int bh = (m / b) + (m % b != 0);
        cout << ah + bh << endl;
    }
    return 0;
}