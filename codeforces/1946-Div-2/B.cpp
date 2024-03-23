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
int A[N] = {0};

int power(int n) {
    if (n == 0) {
        return 1;
    }
    int x = power(n / 2);
    x = (x * x) % mod_;
    if (n % 2) {
        x = (2 * x) % mod_;
    }
    return x;
}

int32_t main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        int tsum_ = 0, sum_ = 0, max_ = 0;
        for (int i = 0; i < n; ++i) {
            tsum_ += A[i];
            if (sum_ < 0) {
                sum_ = 0;
            }
            sum_ += A[i];
            max_ = max(sum_, max_);
        }
        tsum_ %= mod_;
        max_ %= mod_;
        int x = (max_ * power(k)) % mod_;
        tsum_ = (tsum_ - max_) % mod_;
        tsum_ = (tsum_ + mod_) % mod_;
        tsum_ = (tsum_ + x) % mod_;
        cout << tsum_ << endl;
    }
    return 0;
}