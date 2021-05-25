#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
bitset<100>vis;
vvi v,ans;
int j=1;
void BFS(int i)
{
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
           auto u=q.front();
           q.pop();
           for(auto x:v[u])
           {
               if(vis[x])
                {
                    vis[x]=0;
                    ans[j].push_back(x);
                    q.push(x);

                }
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
    int n,m,a,b;
    float cnt=0;
    queue<int>p;
    cin>>n>>m;
    vis.set();
    ans.resize(n+1);
    v.resize(n+1);
   
    while(m--)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
   
    for(int i=1;i<=n;i++)
    {
          if(vis[i])
            {    
                vis[i]=0;
                ans[j].push_back(i);
                BFS(i);
                if(ans[j].size()>=4)
                {
                    cout<<"-1";
                    return 0;
                }
                if(ans[j].size()>=2)
                cnt++;
                if(ans[j].size()==1)
                p.push(i);
                j++;
            }
    }
        if(cnt>n/3)
        {
            cout<<"-1";
            return 0;
        }
        for(int i=1;i<=n;i++)
        {
           if(ans[i].size()==3)
           {
                for(auto x:ans[i])
                cout<<x<<" ";
                cout<<endl;
           }
           else if(ans[i].size()==2)
           {
               for(auto x:ans[i])
               cout<<x<<" ";
               cout<<p.front();
               p.pop();
               cout<<endl;

           }
        }
        while(!p.empty()) 
        {
            cout<<p.front()<<" ";
            p.pop();
            if(p.size()%3==0)
            cout<<endl;
        }

     return 0;
}