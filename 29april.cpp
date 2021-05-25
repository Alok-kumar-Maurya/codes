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
#define endl "\n"
//#include<ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree <int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vvi u(n + 1);
        vi temp(n), temp2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> temp2[i];
        }
        for (int i = 0; i < n; i++)
        {
            u[temp[i]].push_back(temp2[i]);
        }
        vi ans(n, 0);
        for (int i = 1; i <= n; i++)
        {
            sort(u[i].begin(), u[i].end(), greater<int>());
            int m = u[i].size();
            if (m == 0)
                continue;
            vi pre(m, 0);
            pre[0] = u[i][0];
            for (int j = 1; j < m; j++)
                pre[j] = pre[j - 1] + u[i][j];

            for (int j = 1; j <= m; j++)
                ans[j] += pre[(m / j) * j - 1];
        }
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
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
