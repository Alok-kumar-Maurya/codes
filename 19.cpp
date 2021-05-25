#include<bits/stdc++.h>
using namespace std;
map<string,string>v;
map<string,int>vis;
int cnt;
void bfs(string s)
{
           vis[s]=1;
           cnt++;         
           if(!vis[v[s]]&&v.find(v[s])!=v.end())
           bfs(v[s]);
}
void set_vis()
{
    for(auto x:v)
    vis[x.first]=0;
}
void case_change(string &s)
{
          for(int i=0;s[i]!=0;i++)
          {
              if(s[i]>='A'&&s[i]<='Z')
              s[i]+=32;
          }
    
}
int main()
{       
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int ver,ans=0;
    cin>>ver;
    for(int i=1;i<=ver;i++)
    {         
            string a,b,c ;
            cin>>a>>c>>b;
            case_change(a);
            case_change(b);
            v[a]=b;
            ///cout<<a<<" "<<b<<endl;
            //v[b].push_back(a);
            //cout<<a;
    }
    for(auto x:v)
    {          
             set_vis();
             cnt=0;
             bfs(x.first);
             ans=max(cnt,ans);
    }
   cout<<++ans;
} 