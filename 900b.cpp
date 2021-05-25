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
    int a,b,c,check;
    cin>>a>>b>>c;
    double f=(double)a/b;
    int d=a/b;
    if(d==f)
    {
        cout<<"-1";
        return 0;
    }
    cout<<fixed<<setprecision(150);
    cout<<f<<endl;888888888
    f=(f-d)*10;
    int ans=0;
    for(int i=1;i<150;i++)
    {
          d=f;
          cout<<d<<" ";
          if(d==c)
          {
              ans=i;
              break;
          }
          f-=d;
          f*=10;

    }
     if(ans)
     cout<<ans;
     else 
     cout<<"-1";
     return 0;
}