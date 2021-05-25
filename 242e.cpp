#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x, y) cout << "[ " << x << "  " << y << " ]" << endl
#define debugx(x) cout << "[ " << x << " ]" << endl
vi arr;
struct seg
{
    vi pending, tree;
    void initialize(int bit, int n)
    {
        pending.resize(4 * n + 1, 0);
        tree.resize(4 * n + 1, 0);
        build(bit, 0, n - 1, 1);
    }   
    void build(int bit, int l, int r, int idx)
    {    
        if (l == r)
        {
            if (arr[l] & (1 << bit))
                tree[idx] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(bit, l, m, 2 * idx);
        build(bit, m + 1, r, 2 * idx + 1);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
    int query(int qs, int qe, int l, int r, int idx)
    {
        if (qs > qe)
            return 0;
        if (pending[idx] != 0)
        {
            tree[idx] = (r - l + 1) - tree[idx];
            if (l != r)
            {
                pending[2 * idx] ^= 1;
                pending[2 * idx + 1] ^= 1;
            }
            pending[idx] = 0;
        }
        if (l == qs && r == qe)
            return tree[idx];
        int m = (r + l) / 2;
        int left = query(qs, min(m, qe), l, m, idx * 2);
        int right = query(max(m + 1, qs), qe, m + 1, r, 2 * idx + 1);
        return left + right;
    }
    void update(int qs, int qe, int l, int r, int idx)
    {
        if (qs > qe)
            return;
        if (pending[idx] != 0 )
        {
            tree[idx] = (r - l + 1) - tree[idx];
            if (r != l)
            {
                pending[2 * idx] ^= 1;
                pending[2 * idx + 1] ^= 1;
            }
            pending[idx] = 0;
        }
        if (qs == l && qe == r)
        {
            tree[idx] = (r - l + 1) - tree[idx];
            if (r != l)
            {
                pending[2 * idx] ^= 1;
                pending[2 * idx + 1] ^= 1;
            }
            return;
        }
        int m = (l + r) / 2;
        update(qs, min(m, qe), l, m, 2 * idx);
        update(max(m + 1, qs), qe, m + 1, r, 2 * idx + 1);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

} t[20];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < 20; i++)
        t[i].initialize(i, n);
    int m;
    cin >> m;
    while (m --)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < 20; i++)
            {

                int x = t[i].query(l - 1, r - 1, 0, n - 1, 1);
                cout << x << " ";
                ans += ( (1 << i) * x);
            }
            cout << ans << endl;
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            for (int i = 0; i < 20; i++)
            {
                if (val & (1 << i))
                  t[i].update(l - 1, r - 1, 0, n - 1, 1);                
            }
        }
    }
    return 0;
    // THINGS TO KEEP IN MIND
    //   * int overflow, time and memory limits
    //   * Special case (n = 1?)
    //   * Do something instead of nothing and stay organized
    //   * Don't get stuck in one focus
    //   * int l=s.length()-x (s.length()<x) garbage value
    // TIME AND MEMORY LIMITS
    //   * 1 second is approximately 10^8 operations (c++)
    //   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
    //   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
    //   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
    //   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}