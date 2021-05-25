#include<bits/stdc++.h>
using namespace std;    
int row,colom;
queue<pair<int,int>>q;
vector<vector<int>>v;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
pair<int,int>p;
bool checker(int x,int y)
{
     if(x>=1&&x<=row&&y>=1&&y<=colom&&v[x][y]==1)
     return true;
     return false;
}
void  BFS()
{
               while(!q.empty())
               {
                        
                    auto u=q.front();
                    q.pop();
                    if(u.first==-1&&u.second==-1)
                    {
                          if(q.size()!=0)
                          {
                              q.push({-1,-1});
                              p=q.front();
                              
                          }
                          continue;
                    }
                    for(int i=0;i<4;i++)
                    {

                        int newx=dx[i]+u.first;
                        int newy=dy[i]+u.second;

                        if(checker(newx,newy))
                        {
                              v.at(newx).at(newy)=0;
                              q.push({newx,newy});
                        }
                    }


               }
}
int main()
{        

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int k,x,y;
    cin>>row>>colom>>k;
    v.resize(row+1,vector<int>((colom+1),1));

    while(k--)
    {
        cin>>x>>y;
        v.at(x).at(y);
        q.push({x,y});
    }
    p=q.front();
    q.push({-1,-1});
    BFS();
    cout<<p.first<<" "<<p.second<<endl;
    
}