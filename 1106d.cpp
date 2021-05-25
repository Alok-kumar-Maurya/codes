#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
int n,m;
vector<bool>vis;
vector<vector<int>>adj;
vi ans;
void bfs(int current)
{    
     vis[current]=true;
     priority_queue<int,vector<int>,greater<int>> priQ; //min heap
     priQ.push(1);
     while(!priQ.empty())
     {
          int top=priQ.top();
          ans.push_back(top);
          priQ.pop();
          for(auto x:adj[top])
          {
               if(!vis[x])
               {
                  vis[x]=true;
                  priQ.push(x);
               }
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
    cin>>n>>m;
    vis.resize(n+1,false);
    adj.resize(n+1);
    for(int i = 0; i < m ; i++)
    {       
         int a,b;
         cin>>a>>b;
         if(a==b)
         continue;
         adj[a].push_back(b);
         adj[b].push_back(a);
    }  
    
    bfs(1);
    for(auto x:ans) 
    cout<<x<<" ";

 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) runtime error
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}