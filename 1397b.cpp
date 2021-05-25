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
        int n,ans=INT64_MAX;
        cin>>n;
        vi v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        sort(v.begin(),v.end());
        int k=0;
        for(int i=1;1;i++)
        {         
              int total_cost=0,temp=1;
            for(int j=0;j<v.size();j++)
            {         
                     total_cost=total_cost+abs(v[j]-temp);
                     temp=temp*i;
                     
                     if(temp>=1e18)
                     k=1;
                    
            }
            if(k)
            break;
            ans=min(ans,total_cost);
        }
        cout<<ans;
     return 0;
}