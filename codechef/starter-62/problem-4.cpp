#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, flag = 0;
        cin >> n;
        x = 0;
        while (n % 2 == 0)
        {
            x++;
            n /= 2;
        }
        if (x % 2 == 1)
        {
            x--;
            n *= 2;
        }
        for (int i = 0; i * i <= n; ++i)
        {
            int y = n - i * i, z = sqrt(y);
            if (z * z == y)
            {
                cout << (z << (x / 2)) << ' ' << (i << (x / 2)) << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
    }
}
