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
    int n,a,ans=0;
    map<int,int>m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
         cin>>a;
         int pow=1;
         for(int i=1;i<=63;i++)
          {    
              pow*=2;
              if(pow-a<=0)
              continue;
              if(m.find(pow-a)!=m.end())
                {
                    ans+=m[pow-a];
                }
          }
          m[a]++;
    }
    cout<<ans;
     return 0;
}