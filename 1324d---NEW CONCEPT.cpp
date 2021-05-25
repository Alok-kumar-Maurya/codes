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
    int n,ans=0;
    cin>>n;
    vi t(n),s(n);
    for(int i=0;i<n;i++)
      cin>>t[i];
    for(int i=0;i<n;i++)
      {
          int a;
          cin>>a;
          s[i]=t[i]-a;
      }
     sort(s.begin(),s.end());
     for(int i=0;i<n;i++)
     { 
        if(s[i]<=0)
        continue;
        auto it=lower_bound(s.begin(),s.end(),-s[i]+1);
        int len=it-s.begin();
        ans+=(i-len);
     }
     cout<<ans;
     return 0;
}