#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
vi sub,ans;
vi vis;
vvi adj;
bool ok=true;
void dfs(int cur)
{
    
  if(vis[cur]==0)
  {    
      vis[cur]++;
    for(auto x:adj[cur])
          dfs(x);
          vis[cur]=2;
         ans.push_back(cur);

  }
  else if(vis[cur]==1)
  {
       ok=false;
       return;
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
    int n,k;
    cin>>n>>k;
    vis.resize(n+1,0);
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        sub.push_back(a);
    }
    adj.resize(n+1);
    for(int i=1;i<=n;i++)
    {  
        int b,c;
        cin>>b;
        while(b--) 
        {   
            cin>>c;
            adj[i].push_back(c);
        }
    }
    for(int i=0;i<k;i++)
    {  
        if(!vis[sub[i]])
        {     
             ok=true;
             dfs(sub[i]);
             if(ok==false)
             break;
        }
        
        
    }
    if(ok)
    {     
        cout<<ans.size()<<endl;
        for(auto x:ans)
        cout<<x<<" "; 
    }
    else
    {
        cout<<"-1";
    }
    
     return 0;
}