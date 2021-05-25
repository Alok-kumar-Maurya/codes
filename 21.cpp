#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
vvi adj;
bitset<1000000>vis;
void bfs(int i)
{   
      vis[i]=0;
      if(adj[i].size()!=2)
      k=0;
      
      for(auto x:adj[i])
      {
          if(vis[x])
          bfs(x);
      }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,a,m,b;
    cin>>n>>m;
    adj.resize(n+1);
    vis.set();
    
    for(int i=1;i<=m;i++)
    {
             cin>>a>>b;
             adj[a].push_back(b);
             adj[b].push_back(a);
           
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {      
            k=1;
            cnt=adj[i].size();
            bfs(i);
            if(k==1)
            break;
        }
    }
    if(k)
    cout<<"YES";
    else
    cout<<"NO";
    
    
    return 0;
}