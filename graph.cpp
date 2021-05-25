#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>dis;
unordered_map<string,vector<string>>adj;
unordered_map<string,string>nei;
queue<string>a;
void BFS(string src,string des)
{       
 
    
     for(auto x:adj)
     {
         dis[x.first]=INT_MAX;
     }
     a.push(src);
     dis[src]=0;
    while(!a.empty())
    {
               
               auto v=a.front();
               //cout<<v<<"-->";
                a.pop();
                      for(auto x:adj[v])
                      {   
                          if(dis[x]==INT_MAX)
                          {  
                             dis[x]=dis[v]+1;
                             nei[x]=v;
                             a.push(x);
                          }
                      }
               

    }
  //  cout<<dis["up"];
  string x=des;
  cout<<des<<"--->";
  while(src!=x)
  { 
       cout<<nei[x]<<"--->";
       x=nei[x];
  }

}
int main()
{        
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
    
     int v,e;
     string l,m;
     cin>>v>>e;
     for(int i=0;i<e;i++)
     {
         cin>>l>>m;
         adj[l].push_back(m);
         adj[m].push_back(l);
     }
    //     for(auto x:adj)
    //  {
    //      cout<<x.first<<"---->";
    //      for(auto y:x.second)
    //      cout<<y<<",";
    //      cout<<endl;
    //  }      
             
             BFS("ban","up");

}