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
vi vis ;
vector<vi> adj ;
int sizes , have ;
void dfs(int i)
{
    vis[i] = 1 ;
    sizes ++ ;
    have += adj[i].size() ;
    for(auto x : adj[i]) 
    {
        if(!vis[x])
        dfs(x);
    }
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
    int n , m , k ;
    cin >> n >> m >> k ;
    vis.resize(n + 1 , 0) ;
    adj.resize( n + 1);
    vi king(k) ;
    for(int i = 0 ; i < k ; i ++) 
    {
        cin >> king[i];
    }
    while(m--)
    {
        int a ,b ;
        cin >> a >> b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }
    int mx = 0 , ans = 0 ;
    for(int i = 0 ; i < k ; i ++) 
    {  
        sizes = 0 ;
        have = 0 ;
        dfs(king[i]);
        mx = max(mx ,sizes) ;
        ans  +=  ( (sizes - 1 ) * sizes ) / 2  - ( have / 2 );
    }
    for(int i = 1 ; i <= n ; i ++) 
    {
        if(!vis[i])
        {
            sizes = 0 ;
            have = 0;
            dfs(i) ;
            ans += ( ( sizes - 1 ) * sizes ) / 2 - have / 2 ;
            ans += ( mx * sizes) ; 
            mx += sizes ;
        }
    }
    cout << ans << endl;
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