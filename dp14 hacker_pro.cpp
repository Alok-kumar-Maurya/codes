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
vector<vector<pair<int,int>>>adj;
int dp[1 << 14][14][101];
int n ;
int tsp(int mask , int cur , int energy)
{     
    
    if(mask == (1 << n) - 1 ) 
    {
        dp[mask][cur][energy] = 0 ;
        return 0 ;
    }                          
    if(dp[mask][cur][energy] != -1) 
    return dp[mask][cur][energy] ;
    int ans = 1e10;
    for(int j = 0 ; j < n ; j ++)
    {   

        if( (mask & (1 << j) ) == 0)
        {           
                    int newmask = mask | (1 << j) ;
                    if(energy - adj[cur][j].second >= 0)
                    ans = min (ans , adj[cur][j].first + tsp(newmask , j ,energy - adj[cur][j].second));
        }
        
    }
    dp[mask][cur][energy] = ans ;
    return ans ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m ,e ;
    cin >> n >> m >> e;
    adj.resize(n , vector<pair<int,int>>(n)) ; 
    memset(dp , -1 , sizeof(dp));
    for(int i = 0 ; i < m ; i++)
    {
        int u , v , w ,ener;
        cin >> u >> v >> w >> ener;
        u-- ; v-- ;
        adj[u][v] = {w , ener} ;
        adj[v][u] = {w , ener} ;
    }
    int ans =  tsp(1, 0 ,e);
    if( ans == 1e10 ) 
    cout <<"-1\n" ;
    else 
    cout << ans << endl;
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) garbage value
// TIME AND dpRY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}