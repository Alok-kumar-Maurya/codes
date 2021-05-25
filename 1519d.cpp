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
vi a, b;
int n;
int cal(int i, int j, int total)
{
    int temp = 0 , minus = 0 , ans = 0;
    if (i == j)
    {
        i--;
        j++;
    }
    while (i >= 0 && j < n)
    {
        temp += (b[i] * a[j] + b[j] * a[i]);
        minus += (a[i] * b[i] + a[j] * b[j]) ;
        ans = max(ans, total - minus + temp);
        i -- ;
        j ++ ;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &x : a)
        cin >> x;
    int total = 0;
    for (int i = 0 ; i < n ; i ++ )
    {
        cin >> b[i];
        total += ( a[i] * b[i] );
    }
    int ans = total ;
    for (int i = 0; i < n ; i++)
    {
        int x = cal(i, i, total);
        int y = cal(i, i + 1, total);
        ans = max({ans , x , y } );
    }
    cout << ans ;
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