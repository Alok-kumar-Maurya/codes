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
vector<vector<int>>adj;
vector<vector<int>>memo ;
int n ;
int tsp(int mask , int cur)
{     
    if(mask == (1 << n)-1)
    {
        memo[mask][cur] = adj[cur][0] ;
        return memo[mask][cur];
    }                                           //   O(2^n * n)
    if(memo[mask][cur] != -1) 
    return memo[mask][cur] ;
    //debugxy(mask , cur) ;

    int ans = 1e10;
    for(int j = 0 ; j < n ; j ++)
    {   

        if( (mask & (1 << j) ) == 0)
        {           
                    int newmask = mask | (1 << j) ;
                    ans = min ( ans , adj[cur][j] + tsp(newmask , j ));
        }
    }
    memo[mask][cur] = ans ;
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
    int m ;
    cin >>m >> n ;
    adj.resize(n , vi(n)) ;
    memo.resize(1llu << n , vi( n , -1)) ;
    for(int i = 0 ; i < m ; i++)
    {
        int u , v , w ;
        cin >> u >> v >> w;
        adj[u][v] = w ;
        adj[v][u] = w ;
    }
    cout << tsp(1,0);
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