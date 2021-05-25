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
#define mod 1000000007
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n , m , p  ;
    cin >> n >> m >> p ;
    vector<vector<int>>grid(n , vi(m , 1) ) ,dp(n , vi( m, 0)) ;
    while(p--) 
    {
        int a , b ;
        cin >> a >> b ;
        a--; b -- ;
        grid[a][b] = 0 ;
    }
    int moves  = 1 ;
    dp[0][0] = 1 ;
    for(int i = 1 ; i < m ; i ++) 
    {        
            if(grid[0][i] == 0) 
            {
                moves = 0;
            }
            dp[0][i] = moves;
    }
    moves = 1;
    for(int i = 1 ; i < n ; i ++) 
    {        
            if(grid[i][0] == 0) 
            {
                moves = 0;
            }
            dp[i][0] =  moves;
    }
    for(int i = 1 ; i < n ; i++) 
    {
        for(int j = 1 ; j < m ; j++) 
        {   
            if(grid[i][j])
            dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
        }
    }

    cout << (dp[n-1][m-1]) % mod << endl;
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