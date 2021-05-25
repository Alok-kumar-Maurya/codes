#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<"[ "<<x<<"  "<<y<<" ]"<< endl
#define debugx(x) cout <<"[ "<< x <<" ]"<<endl
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n , m  ;
    cin >> n >> m ;
    vector<vector<int>> cake( n , vi(n , 0) ) ,dp( n ,vi(n , 0));
    for(int  i = 0 ; i < m ; i++) 
    {
        int x , y ; 
        cin >> x >> y ;
        x-- ;
        y-- ;
        cake[x][y] = 1;
    }
    dp[0][0] = cake[0][0];
    for(int i = 1 ; i < n ; i++)
    {
        dp[i][0] = dp[i-1][0] + cake[i][0];
        dp[0][i] = dp[0][i-1] + cake[0][i];
    }
    for(int i = 1 ; i < n ; i++)
    {
       for(int j = 1 ; j < n ; j++) 
       {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + cake[i][j];
       }
    }
    int ans = 0 ;
    for(int i = 0 ; i <= n - 2 ; i++)
    {
       for(int j = 0 ; j <= n - 2  ; j++) 
       {
              int first = dp [i][j] ;
              int second = dp[n - 1][j] - first ;
              int third = dp[i][n - 1] - first ;
              int fourth = dp[n - 1][n - 1] - first - second - third ;
              int mini = min({first , second , third , fourth}) ;
              ans = max ( mini , ans );
       }
    }
    cout << ans << endl ;

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
// 6 13
// 1 2
// 1 3
// 2 1
// 2 4
// 2 5
// 3 2
// 4 2     ans = 3
// 4 3
// 4 6
// 5 1 
// 5 4
// 5 5 
// 6 2

}