#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
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
    map<int,pair<int,int>>m;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        m[a].first++;
        if(a!=b)
        m[b].second++;
    }
    int maxi=-1,ans=-1;
    for(auto x:m)
    {     
        int y=x.second.second+x.second.first;
        if(y>=(n+1)/2)
        {
             if(maxi<x.second.first)
             {
              maxi=x.second.first;
              ans=x.second.second;
             }   
        }
    }

     if(maxi==-1&&ans==-1)
     cout<<"-1";
     else 
     {
          if((n+1)/2-maxi<=0)
          cout<<"0";
          else 
          cout<<(n+1)/2-maxi;
     }
}