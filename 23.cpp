#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define  ll long long int
int n,m,ans;
bitset<100001>vis;
void bfs(int a)
{        
       queue<pair<int,int>>q;
       q.push({a,0});
       while(!q.empty())
       {
         auto u=q.front();
         if(u.first==m)
         { 
           ans=u.second;
           break;
         }
         q.pop();
         if(u.first*2<100001&&vis[u.first*2])
         {
            q.push({u.first*2,u.second+1});
            vis[u.first*2]=0;
         }
         if(u.first-1>=1&&vis[u.first-1])
         {
              q.push({u.first-1,u.second+1});
              vis[u.first-1]=0;
         }
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
    vis.set();
    cin>>n>>m;
    bfs(n);
    cout<<ans;
    return 0;
}
