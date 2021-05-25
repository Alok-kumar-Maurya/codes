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
void print(vi vis , int a) 
{
    for(int i = 1 ;i < vis.size() ;i++)
    {
         if(vis[i] == a) 
         cout << i <<" " ;
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
    int t ;
    cin >> t ;
    while(t--) 
    {
        int  n , m ; 
        cin >> n >> m ;
        vi vis(n+1 , 0);
        vector<vector<int>>adj(n+1 );
        while(m--) 
        {
           int a , b ;
           cin >> a >> b; 
           adj[a].push_back(b);
           adj[b].push_back(a);
        }
        queue<int>q;
        vis[1]  = 1;
        q.push(1);
        while (q.size())
        {
            auto u = q.front();
            q.pop() ;
            for(auto x :adj[u] ) 
            {   
                if(!vis[x])
                {
                  vis[x] = 3 - vis[u];
                  q.push(x);
                }
            }
        }
        int cnt1 = 0 ;
        int cnt2 = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(vis[i] == 1)
            cnt1++;
            if(vis[i] == 2)
            cnt2++;
        }
        if(cnt1 >= cnt2 ) 
        {
             cout << cnt2 << endl;
             print(vis,2);
        }
        else 
        {
             cout << cnt1 << endl;
             print(vis,1);
        }
        cout << endl;

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