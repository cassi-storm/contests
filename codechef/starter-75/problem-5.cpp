#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int dp[301][45010];

int32_t main()
{
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].first;
            a[i].second = i + 1;
            sum += a[i].first;
        }
        if (sum % 2)
        {
            cout << -1 << endl;
            continue;
        }
        memset(dp, 0, sizeof dp);
        sort(a.begin(), a.end());
        dp[0][0] = 1;
        int v = sum / 2, x;
        for (int i = 1; i <= n; ++i)
        {
            x = a[i - 1].first;
            for (int j = 0; j < x; ++j)
                dp[i][j] = dp[i - 1][j];
            for (int j = x; j <= v; ++j)
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - x];
        }
        if (!dp[n][v])
        {
            cout << -1 << endl;
            continue;
        }
        x = v;
        int p = n;
        list<pair<int, int>> left, right;
        while (p > 0)
        {
            if (dp[p - 1][x])
            {
                left.push_front(a[p - 1]);
            }
            else
            {
                right.push_front(a[p - 1]);
                x -= a[p - 1].first;
            }
            --p;
        }
        int min_;
        auto ptr = right.begin();
        list<pair<int, int>> ans;
        for (auto &i : left)
        {
            while (i.first)
            {
                if (!ptr->first)
                    ++ptr;
                min_ = min(ptr->first, i.first);
                i.first -= min_;
                ptr->first -= min_;
                ans.push_back({i.second, ptr->second});
            }
        }
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}
