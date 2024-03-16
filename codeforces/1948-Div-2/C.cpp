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
int D[2][N] = {0};

vector<pair<int, int>> dr = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> A(2, "");
        cin >> A[0] >> A[1];
        for (int i = 0; i < n; ++i) {
            D[0][i] = 0;
            D[1][i] = 0;
        }
        bool flag = false;
        queue<int> q;
        q.push(0);
        while (q.size()) {
            if (D[1][n - 1]) {
                flag = true;
                break;
            }
            int K = q.front();
            q.pop();
            int y = (K % 100) / 10, x = K / 100, m = 1 - K % 10;
            if (m == 1) {
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dr[i].first;    
                    int ny = y + dr[i].second;
                    int nK = nx * 100 + ny * 10 + 1;
                    if (0 > nx || nx >= n || 0 > ny || ny > 1) {
                        continue;
                    }
                    if (D[ny][nx] & 2) {
                        continue;
                    }
                    D[ny][nx] |= 2;
                    q.push(nK);
                }
            } else {
                int nx = x;
                if (A[y][x] == '<') {
                    --nx;
                } else {
                    ++nx;
                }
                int nK = nx * 100 + y * 10;
                if ((D[y][nx] & 1) == 0) {
                    D[y][nx] |= 1;
                    q.push(nK);
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}