#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 1e6 + 10;
int A[N] =  {0};
char C[N] =  {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        char p = s[0];
        int lst = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (p != s[i]) {
                C[lst] = p;
                A[lst++] = cnt;
                cnt = 0;
            }
            ++cnt;
            p = s[i];
        }
        C[lst] = p;
        A[lst++] = cnt;
        int min_ = 0;
        for (int i = 1; i < lst - 1; ++i) {
            if (A[i - 1] > 0 && C[i - 1] == 'm' &&  A[i] == 1 && C[i] == 'a' && A[i + 1] > 0 && C[i + 1] == 'p') {
                if (A[i + 1] == 1) {
                    A[i + 1] = 0;
                } else {
                    A[i] = 0;
                }
                min_ += 1;
            }
            if (A[i - 1] > 0 && C[i - 1] == 'p' &&  A[i] == 1 && C[i] == 'i' && A[i + 1] > 0 && C[i + 1] == 'e') {
                A[i] = 0;
                min_ += 1;
            }
        }
        cout << min_ << endl;
    }
    return 0;
}