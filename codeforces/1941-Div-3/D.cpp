#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 1e3 + 10;
int A[N] = {0};
char C[N] = {0};
int V[N] = {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        --x;
        queue<pair<int, int>> q;
        set<pair<int, int>> set_;
        q.push({x, 0});
        set_.insert({x, 0});
        for (int i = 0; i < m; ++i) {
            cin >> A[i] >> C[i];
        }
        int lst = 0;
        while (q.size()) {
            auto cur = q.front();
            int i = cur.second;
            q.pop();
            if (i == m) {
                V[lst++] = cur.first + 1;
                continue;
            }
            if (C[i] != '1') {
                int nx = (cur.first + A[i] + n) % n;
                if (!set_.count({nx, i + 1})) {
                    q.push({nx, i + 1});
                    set_.insert({nx, i + 1});
                }
            }
            if (C[i] != '0') {
                int nx = (cur.first - A[i] + n) % n;
                if (!set_.count({nx, i + 1})) {
                    q.push({nx, i + 1});
                    set_.insert({nx, i + 1});
                }
            }
        }
        sort(V, V + lst);
        cout << lst << endl;
        for (int i = 0; i < lst; ++i) {
            cout << V[i] << " ";
        }
        cout << endl;
    }
    return 0;
}