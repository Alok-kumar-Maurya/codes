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
#define endl  "\n" 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int dp[200001][10] ;
    int mod = 1e9 + 7 ;
    for(int i = 0 ; i < 10 ; i ++ ) 
    dp[0][i] = 1 ;
    for(int i = 1 ; i < 200001 ; i ++ ) 
    {    
       int a[10] = { };
       for(int j = 1 ; j <= 10 ; j ++ ) 
       {
           a[j % 10] = ( 1 + dp[i - 1][(j - 1)%10] ) % mod ; 
       }
       a[1] = ( 1 + dp[i - 1][9] ) % mod ;
       for(int j = 0 ; j < 10 ; j ++ ) 
       dp[i][j] = a[i] ;
    }
    int t ;
    cout <<"lskl";
    cin >> t ;
    while(t -- ) 
    {
        int n , m ;
        cin >> n >> m ;
        int ans = 0;
        while(n) 
        {
            ans += dp[m][n % 10] ;
            ans %= mod ;
            n /= 10 ;
        }
        cout << ans << endl;
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