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
vvi adj;
vi maxh;
int dfs(int cur , int par)
{    
    int maxi = -1 ;
    for(auto x : adj[cur])
    { 
        if(x == par) 
        continue ;   
        maxi = max(maxi , dfs(x , cur)) ;
    } 
    maxh[cur] = maxi+1;
    return maxi+1 ;
     
}
int ans = 0 ;
void dfs2(int cur ,int par)
{
     if(adj[cur].size() == 1)
     {
        ans = max(ans , maxh[cur]) ;
     }
     else 
     {
         multiset<int>s ;
         for(auto x  :adj[cur])
         {
             if(x == par) 
             continue ;
             s.insert(maxh[x]) ;
         }
         if(s.size() > 1)
         {
                auto it = s.rbegin() ;
                int fi = *it ;
                it++ ;
                int se = *it ;
                ans = max(ans , 2 + fi + se) ;
         } 
         else 
         {
             ans = max(ans , *s.begin());
         }
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
    int n ;
    cin >> n ;
    adj.resize(n+1) ;
    maxh.resize(n+1);
    for(int i =0 ; i < n-1 ; i++)
    {
        int a, b ;
        cin >> a >> b ; 
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    } 
    dfs(1 , -1) ;
    dfs2(1 , -1);
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