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
    int n,sum=0;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
      sum+=v[i];
    }
    int ans=0,prefixSum=0;
    for(int i=0;i<n-1;i++)
    {
         prefixSum+=v[i];
         if(prefixSum==sum-prefixSum)
         ans++;
    }
    cout<<ans;
     return 0;
}