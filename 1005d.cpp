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
    string s;
    vi v;
    cin>>s;
    for(int i=0;i<s.length();i++)
    v.push_back(s[i]-'0');
    
    for(int i=1;i<v.size();i++)
    v[i]=v[i]+v[i-1];
    
    for(int i=0;i<v.size();i++)
    v[i]=v[i]%3;
       
    int cnt0=0,cnt2=0,cnt1=0,ans=0,k=1;
    for(int i=0;i<v.size();i++)
    {          
           if(v[i]==0)
            { 
                if(k)
                {
                   ans++;
                   k=0;
                   cnt0=1;cnt2=0;cnt1=0;
                }
                else
                {
                  cnt0++;
                }
                
                
            }
            else if(v[i]==1)
            cnt1++;
            else 
            cnt2++;
            
           
                       
            if(cnt0==2||cnt1==2||cnt2==2) 
            { 
              cnt1=0;cnt2=0;cnt0=0;
              ans++;
              k=0;
              i--;
            }
        
        
    }
     if(cnt0&&ans==0)
     ans++;
     cout<<ans;
     return 0;
}