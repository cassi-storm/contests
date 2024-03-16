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
int D[N] = {0};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m, idx;
        cin >> n >> m;
        idx = n + 1;
        map<int, vector<int>> map_;     
        map<int, int> colors;   
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            auto k = colors.find(c);
            if (k == colors.end()) {
                colors[c] = idx;
                ++idx;
            }
            c = colors[c];
            map_[u].push_back(c);
            map_[v].push_back(c);
            map_[c].push_back(u);
            map_[c].push_back(v);
        }
        int st, ed;
        cin >> st >> ed;
        for (int i = 0; i <= idx; ++i) {
            D[i] = -1;
        }
        D[st] = 0;
        queue<int> q;
        q.push(st);
        int dist = -1;
        while (q.size()) {
            if (D[ed] != -1) {
                dist = D[ed] / 2;
                break;
            }
            int x = q.front();
            q.pop();
            for (auto i : map_[x]) {
                if (D[i] == -1) {
                    D[i] = D[x] + 1;
                    q.push(i);
                }
            }
        }
        cout << dist << endl;
    }
    return 0;
}