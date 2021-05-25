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
    vi v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int positon,ans=0;
    for(int i=0;i<n;i++)
     {
             auto it=upper_bound(v.begin(),v.end(),v[i]+5);
             if(it==v.end())
             {  
                 positon=n-i;
                 ans=max(ans,positon);
                 break;
             }
             else 
             {
                  positon=it-v.begin();
                  ans=max(ans,positon-i);
             }
     }
     cout<<ans;
}