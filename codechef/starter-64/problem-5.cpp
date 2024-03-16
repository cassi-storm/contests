#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int fsqrt(int n)
{
    int x = 0;
    for (int i = 1 << 30; i > 0; i >>= 1)
    {
        x += i;
        if (x * x > n)
            x -= i;
    }
    return x;
}

int32_t main()
{
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        map<int, int> p;
        p[0] = 0;
        int tp, x, min_;
        for (auto i : a)
        {
            map<int, int> map_;
            map_[i] = 0;
            queue<int> q;
            q.push(i);
            while (q.size())
            {
                tp = q.front();
                q.pop();
                if (tp == 1)
                    continue;
                x = fsqrt(tp);
                if (map_.find(x) == map_.end())
                    map_[x] = map_[tp] + 1, q.push(x);
                if (tp > 1e9)
                    continue;
                x = tp * tp;
                if (map_.find(x) == map_.end())
                    map_[x] = map_[tp] + 1, q.push(x);
            }
            min_ = 1e18;
            for (auto &j : map_)
            {
                auto it = p.upper_bound(j.first);
                it = prev(it);
                min_ = j.second = min(j.second + it->second, min_);
            }
            p = map_;
        }
        min_ = 1e18;
        for (auto i : p)
            min_ = min(min_, i.second);
        cout << min_ << endl;
    }
    return 0;
}
