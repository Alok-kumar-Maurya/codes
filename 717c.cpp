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
bool canPartition(vector<int> &nums)
{

    int sum = 0, n = nums.size();
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum & 1)
        return false;
    sum /= 2;
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - nums[i] >= 0)
            {
                if (dp[i][j] || dp[i][j - nums[i]])
                    dp[i + 1][j] = 1;
            }
        }
    }
    return dp[n][sum];
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
    int n;
    cin >> n;
    vi v(n);
    for (auto &x : v)
        cin >> x;
    if (!canPartition(v))
        cout << "0" << endl;
    else
    {
        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] % 2 != 0)
                {
                    cout << "1 " << endl
                         << i + 1 << endl;
                    return 0;
                }
                else
                    v[i] /= 2;
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