#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        set<int,greater<int>>se;
        int n,a;
        vi v;
        cin>>n;
        for(int i=0;i<n;i++)
          {  
               cin>>a;
               v.push_back(a);
               se.insert(a);
          }
          if(se.size()==1)
          cout<<"-1"<<endl;
          else
          {
              for(int i=0;i<v.size();i++)
              {        
                     int s=*se.begin();
                     if(v[i]==s)
                    {            
                        if(i==0)
                         {     
                             if(v[i+1]<s)
                             {cout<<i+1<<endl;
                             break;}
                         }
                        else if(i==v.size()-1)
                         {        
                              if(v[i-1]<s)
                              {cout<<i+1<<endl;
                              break;}
                         }
                        else  if(v[i+1]<s||v[i-1]<s)
                         {
                             cout<<i+1<<endl;
                             break;
                         }
                         

                    }

                
              }
          }
          se.clear();
          
    }
     return 0;
}