#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
vector<vector<int>>adj;
bool ok=false;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int r,c;
bool checker(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c&&adj[x][y]==1)
    return true;
    return false;

}
bool findcenter(int x,int y)
{

       for(int i=0;i<=3;i++)
       {
          int  newx=x+dx[i];
          int  newy=y+dy[i];
          if(!checker(newx,newy))
            return false;
       }
      return true;
}
void dfs(int x,int y,int index)
{      
       adj[x][y]=0;
       int newx=x+dx[index];
       int newy=y+dy[index];
       if(checker(newx,newy))
       dfs(newx,newy,index);
       
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
    cin>>r>>c;
    adj.resize(r,vector<int>(c,0));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {    
            char s;
            cin>>s;
            if(s=='*')
            adj[i][j]=1;
            else 
            adj[i][j]=0;
        }
    }
    bool breaK=false;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(adj[i][j]==1&&findcenter(i,j))
            {
                      
                    for(int k=0;k<=3;k++)
                     {
                         dfs(i,j,k);
                     }
                    ok=true;
                    breaK=true;
                    break;
            }
        }
        if(breaK)
        break;
    }
    for(auto x:adj)
    {
        for(auto y:x)
        {
            if(y==1)
            ok=false;
        }

    }
    if(ok)
    cout<<"YES";
    else 
    cout<<"NO";
    return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}