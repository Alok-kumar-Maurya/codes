#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define int long long 
vvi adj;
vi color;
void dfs(int cur)
{ 
         for(auto x:adj[cur])
         {
               if(color[x]==0)
                {
                     color[x]=3-color[cur];
                     dfs(x);
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
    int n;
    cin>>n;
    adj.resize(n+1);
    color.resize(n+1,0);
    for(int i=0;i<n;i++)
    {    
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    color[1]=1;
    dfs(1);
    int cnt1=0,cnt2=0;
    for(auto x:color)
    {
        if(x==1)
        cnt1++;
        else if(x==2)
        cnt2++;
    }
    cout<<(cnt1*cnt2)-(n-1);
   return 0;
}