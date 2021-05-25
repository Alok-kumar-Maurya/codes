#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
vvi adj;
int dx[]={0,-1,0,1,-1,-1,1,1};
int dy[]={-1,0,1,0,1,-1,-1,1};
int ans,r1,r2,c1,c2,bishop,king=0;
bool checker(int x,int y)
{
    if(x>=1&&x<=8&&y>=1&&y<=8&&adj[x][y])
    return true;
    return false;
}
struct i_j
{
    public:
    pair<int,int>c;
    int time;
};
queue<i_j>q;

void dfs(int i,int j,int st, int en)
{
     while(!q.empty())
     {      
          auto u=q.front();
          q.pop();
          adj[u.c.first][u.c.second]=0;
          if((u.c.first+u.c.second==r2+c2)&&bishop)
          {
            ans=u.time;
            bishop=0;
          }
          if((u.c.first-u.c.second==r2-c2)&&bishop)
          {
             ans=u.time;
             bishop=0;
          }
          if(u.c.first==r2&&u.c.second==c2&&king)
           {
            ans=u.time;
            king=0;
           }
            
        for(int k=st;k<=en;k++)
          {
              int newx=dx[k]+u.c.first;
              int newy=dy[k]+u.c.second;
              if(checker(newx,newy))
              q.push({{newx,newy},u.time+1});
               
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
    
         cin>>r1>>c1>>r2>>c2;
         
         if(r1==r2||c1==c2)
         cout<<"1 ";
         else
         cout<<"2 ";
         

         ans=0;bishop=1;
         adj.resize(9,vi(9,1));
         q.push({{r1,c1},0});
         dfs(r1,c1,4,7);
         if((r1+c1==r2+c2)||r1-c1==r2-c2)
         cout<<"1 ";
         else if(bishop==0)
         cout<<"2 ";
         else
         cout<<"0 ";
         bishop=0;
         
        
        
         ans=0;king=1;
         adj.resize(9,vi(9,1));
         for(int i=1;i<=8;i++)
         for(int j=1;j<=8;j++)
         adj[i][j]=1;
        
         q.push({{r1,c1},0});
         dfs(r1,c1,0,7);

         cout<<ans<<" ";

      
     return 0;
}