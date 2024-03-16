#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

struct node
{
    bool end;
    node *child[2];
    node()
    {
        child[0] = child[1] = NULL;
    }
};

class XORTrie
{
private:
    node *root;

public:
    XORTrie()
    {
        root = new node();
    }
    ~XORTrie()
    {
        deAllocate(root);
    }
    void deAllocate(node *croot)
    {
        if (!croot)
            return;
        deAllocate(croot->child[0]);
        deAllocate(croot->child[1]);
        delete (croot);
    }
    void insert(int x, int ln, string &s)
    {
        node *node_ = root;
        for (int i = x; i < x + ln; ++i)
        {
            if (!node_->child[s[i]])
                node_->child[s[i]] = new node();
            node_ = node_->child[s[i]];
        }
    }
    void get(int x, int ln, string &s, vector<int> &a)
    {
        int big = 0;
        node *node_ = root;
        for (int i = x, j = 0; i < x + ln; ++i, ++j)
        {
            if (node_->child[1 - s[i]])
            {
                if (a[j] == 0)
                    big = 1;
                if (big || a[j] == 1)
                    a[j] = 1;
                node_ = node_->child[1 - s[i]];
            }
            else
            {
                if (!big && a[j] == 1)
                    return;
                else
                    a[j] = 0;
                node_ = node_->child[s[i]];
            }
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j])
                    continue;
                k = max(k, min(j - i, n - j));
            }
            s[i] -= 48;
        }
        if (k == 0)
        {
            cout << 0 << endl;
            continue;
        }
        k = min(k, n / 2);
        vector<int> a(k, 0);
        XORTrie trie;
        for (int i = k; i < n - k + 1; ++i)
        {
            trie.insert(i - k, k, s);
            trie.get(i, k, s, a);
        }
        int large = 0;
        for (auto i : a)
        {
            large = (2 * large + i) % mod_;
        }
        cout << large << endl;
    }
    return 0;
}
