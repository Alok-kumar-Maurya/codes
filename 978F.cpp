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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>v(n+1);
    for(int i=1;i<=n;i++)
    {    
        int a;
        cin>>a;
        v[i]={a,i};
    }
    map<int,int>quarrel;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        if(v[a].first==v[b].first)
        continue;
        else if(v[a].first>v[b].first)
        quarrel[a]++;
        else 
        quarrel[b]++;

    }
    sort(v.begin(),v.end());
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++)
    {        
           pair<int,int>s={v[i].first,0};
           auto it1=lower_bound(v.begin(),v.end(),s)-v.begin()-1;
           ans[v[i].second]=it1-quarrel[v[i].second];

    }
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
    return 0;
}       