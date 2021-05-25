#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
vector<vector<int>>forest;
vector<bool>vis;
void dfs(int i)
{
       vis[i]=true;
       for(auto x:forest[i])
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
    int n,a,b;
    cin>>n;
    forest.resize(n+1);
    vis.resize(n+1,false);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        forest[a].push_back(i);
        forest[i].push_back(a);
    }
    int tree=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            tree++;
            dfs(i);
        }
    }
    cout<<tree;
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