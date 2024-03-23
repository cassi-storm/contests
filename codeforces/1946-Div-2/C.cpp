#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

const int N = 1e5 + 10;
vector<int> G[N];

int K = 0;

int dfs(int node, int min_, int p) {
    int sum_ = 1;
    for (auto i : G[node]) {
        if (i == p) {
            continue;
        }
        int x = dfs(i, min_, node);
        sum_ += x;
    }
    if (sum_ >= min_) {
        sum_ = 0;
        ++K;
    }
    return sum_;
}

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int i = 0, j = n;
        while (i < j) {
            int x = (i + j) / 2;
            K = 0;
            dfs(1, x, 0);
            if (K > k) {
                i = x + 1;
            } else {
                j = x;
            }
        }
        cout << (i - 1) << endl;
    }
    return 0;
}
