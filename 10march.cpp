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
int mod = 1e9 + 7;
vvi adj ;
vi fact(500001, 1) ; 
int ans ;
int dfs(int cur , vi &vis) 
{
    vis[cur] = 1 ;
    int possible = 0;
    for(auto x : adj[cur]) 
    {
           if(!vis[x])
           {
                possible += dfs(x , vis); 
           }
    }
    return fact[ possible ];
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
    int t;
    cin >> t;
    for(int i = 2 ; i < 500000 ; i ++ ) 
    fact[i] = ( fact[i - 1] * i ) % mod ;
    while (t--)
    {
        
        int n , k ;
        cin >> n >> k ;
        vector<pii> p ;
        adj.resize(n);
        for(int i = 0 ; i < n - 1 ; i ++ ) 
        {
            int a ,b ;
            cin >> a >> b ;
            a -- ;
            b -- ;
            adj[a].push_back(b); 
            adj[b].push_back(a);
        } 
        for(int i = 0 ; i < n ; i ++ ) 
        {       
                vi vis(n , 0 );
                int c = dfs(i , vis);
                p.push_back({c , i}) ;
        }
        sort(p.begin() , p.end() , greater<pii>()) ;
        k = min( (int)p.size() , k) ;
        cout << p[k - 1].second + 1 << " "<<p[k - 1].first << endl;
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