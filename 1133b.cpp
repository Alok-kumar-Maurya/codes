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
    map<int,int>m;
    for(int i=0;i<n;i++)
    {    
        int a;
        cin>>a;
        m[a%k]++;
    }
    int ans=0;
    if(m.find(0)!=m.end())
      ans+=m[0]/2;
    for(int i=1;i<k;i++)
    {
        if(m.find(i)!=m.end())
        {      

            if(k-i==i)
            ans+=m[i]/2;
                   
            
           else if(m.find(k-i)!=m.end()) 
             { 
                 int minimum=min(m[i],m[k-i]);
                 ans+=minimum;
                 m[i]-=minimum;
                 m[k-i]-=minimum;

             }
        }
    }
    cout<<ans*2<<endl;
     return 0;
}