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
vector<vector<int>> adj  ;
vi parent;
vi optimize ;
int dfs(int i , int par)
{    
     int lcm = 1 ;
     int cnt = 0 ;
     for(auto x : adj[i]) 
     {
         if(x == par) 
            continue; 
         int y = dfs(x , i );
         lcm = ( lcm * y ) / __gcd( lcm , y ) ;
         cnt ++ ;
     }
     optimize[i] = max((int)1 , cnt * lcm );
     return optimize[i] ;
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
    adj.resize( n + 1) ;
    optimize.resize( n + 1 );
    parent.resize( n + 1 );
    parent[1] = -1 ;
    for(int i = 2 ; i <= n ; i ++)
    {
           int a ;
           cin >> a ;
           parent[i] = a ;
           adj[a].push_back(i);
           adj[i].push_back(a);
    }
    dfs(1 , -1);
    for(int i = 1 ; i <= n ;  i ++)
    {
        debugxy( i , optimize[i]);
    }
    int q; 
    cin >> q ;
    while (q--)
    {
        int node , task ;
        cin >> node >> task ;
        int ans = 0 ;
        queue<pair<int,int>> pq ;
        pq.push({node , task});
        while(pq.size())
        {   
            bool ok = false;
            auto top = pq.front() ;
            pq.pop(); 
            int size = adj[top.first].size();
            if(size == 1 || size == 0)
            continue ;
            if(top.second % optimize[top.first] == 0) 
            continue ;
            if(top.first != 1) 
            size -- ;

            if(top.second % size == 0) 
                ok = true ;
            else 
                ans += top.second ;
               
            
            if(ok)
            for(auto x : adj[top.first]) 
            {
                if(x == parent[top.first])
                continue ;
                pq.push({x , top.second / size });
            }
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